

# CLR 寄宿
寄宿(hosting)使任何应用程序都能利用 CLR 的功能。特别要指出的是，它使现有的应用程序至少能部分使用托管代码编写。另外，寄宿还为应用程序提供了通过编程来进行自定义和扩展的能力。

.NET Framework 在 Windows 平台的顶部运行。这意味着 .NET Framework 必须用 Windows 能理解的技术来构建。首先，所有托管模块和程序集文件都必须使用 Windows PE 文件格式，而且要么是 Windows EXE 文件，要么是 DLL 文件。

开发 CLR 时，Microsoft 实际是把它实现成包含一个 DLL 中的 COM 服务器。也就是说，Microsoft 为 CLR 定义了一个标准的 COM 接口，并为该接口和 COM 服务器分配了 GUID。 安装 .NET Framework 时，代表 CLR 的 COM 服务器和其他 COM 服务器一样在 Windows 注册表中注册。要了解这方面的更多信息，可参考与 .NET Framework SDK 一起发布的 C++ 头文件 MetaHost.h。该头文件中定义了 GUID 和非托管 ICLRMetaHost 接口。

任何 Windows 应用程序都能寄宿(容纳)CLR。但不要通过调用 CoCreateInstance 来创建 CLR COM 服务器的实例，相反，你的非托管宿主应该调用 MetaHost.h 文件中声明的 CLRCreateInstance 函数。CLRCreateInstance 函数在 MSCorEE.dll 文件中实现，该文件一般在C:\Windows\System32 目录中。这个 DLL 被人们亲切地称为“垫片”(shim)，它的工作是决定创建哪个版本的CLR；垫片 DLL 本身不包含 CLR COM 服务器。

Windows 进程完全可以不加载 CLR，只有在进程中执行托管代码时才进行加载。在 .NET Framework 4 之前，CLR 只允许它的一个实例寄宿在 Windows 进程中。换言之，在一个进程中，要么不包含任何 CLR，要么只能包含 CLR v1.0, CLR v1.1 或者 CLR 2.0 之一。每进程仅一个版本的 CLR 显然过于局限。例如，这样 Microsoft Office Outlook 就不能加载为不同版本的 .NET Framework 生成和测试的两个加载项了。

但是，随着 .NET Framework 4 的发布，Microsoft 支持在一个 Windows 进程中同时加载 CLR v2.0 和 v4.0，为 .NET Framework 2.0 和 4.0 写的不同组件能同时运行，不会出现任何兼容性问题。这是一个令人激动的功能，因为它极大扩展了 .NET Framework 组件的应用场合。可利用 CLrVer.exe 工具检查给定的进程加载的是哪个(哪些)版本的 CLR。

一个 CLR 加载到 Windows 进程之后，便永远不能卸载；在 ICLRRuntimeHost 接口上调用 AddRef 和 Release 方法是没有作用的。CLR 从进程中卸载的唯一途径就是终止进程，这会造成 Windows 清理进程使用的所有资源。

---------------------------

# AppDomain

## 什么是AppDomain
CLR COM 服务器初始化时会创建一个 AppDomain。AppDomain 是一组程序集的逻辑容器。 CLR 初始化时创建的第一个 AppDomain 称为“默认 AppDomain”，这个默认的 AppDomain 只有在 Windows 进程终止时才会被销毁。

除了默认 AppDomain，正在使用非托管 COM 接口方法或托管类型方法的宿主还可要求 CLR 创建额外的 AppDomain。

-----------------

## AppDomain的功能
AppDomain 是为了提供隔离而设计的。下面总结了 AppDomain 的具体功能。

- **一个 AppDomain 的代码不能直接访问另一个 AppDomain 的代码创建的对象**
    - 一个 AppDomain 中的代码创建了一个对象后，该对象便被该 AppDomain “拥有”。换言之，它的生存期不能超过创建它的代码所在的 AppDomain。一个 AppDomain 中的代码要访问另一个 AppDomain 中的对象，只能使用“按引用封送”(marshal-by-reference)或者“按值封送”(marshal-by-value)的语义。这就强制建立了清晰的分隔边界，因为一个 AppDomain 中的代码不能直接引用另一个 AppDomain 中的代码创建的对象。这种隔离使 AppDomain 能很容易地从进程中卸载，不会影响其他 AppDomain 正在运行的代码。
</br>
- **AppDomain 可以卸载**
  - CLR 不支持从 AppDomain 中卸载特定的程序集。但可以告诉 CLR 卸载一个 AppDomain，从而卸载该 AppDomain 当前包含的所有程序集。
</br>

- **AppDomain 可以单独保护**
    - AppDomain 创建后应用一个权限集，它决定了向这个 AppDomain 中运行的程序集授予的最大权限，所以当宿主加载一些代码后，可以保证这些代码不会破坏(或读取)宿主本身使用的一些重要数据结构。
</br>

- **AppDomain 可以单独配置**
    - AppDomain 创建后会关联一组配置设置。这些设置主要影响 CLR 在 AppDomain 中加载程序集的方式。涉及搜索路径、版本绑定重定向、卷影复制以及加载器优化。


</br>
</br>


Windows 的一个重要特色是让每个应用程序都在自己的进程地址空间中运行。这就保证了一个应用程序的代码不能访问另一个应用程序使用的代码或数据。进程隔离可防范安全漏洞、数据破坏和其他不可预测的行为，确保了 Windows 系统以及在它上面运行的应用程序的健壮性。遗憾的是，在 Windows 中创建进程的开销很大。Win32 CreateProcess 函数的速度很慢，而且 Windows 需要大量内存来虚拟化进程的地址空间。

但是，如果应用程序安全由托管代码构成(这些代码的安全性可以验证)，同时这些代码没有调用非托管代码，那么在一个 Windows 进程中运行多个托管应用程序是没有问题的。AppDomain 提供了保护、配置和终止其中每一个应用程序所需的隔离。


图 22-1 演示了一个 Windows 进程，其中运行着一个 CLR COM 服务器。该 CLR 当前管理着两个 AppDomain(虽然在一个 Windows 进程中可以运行的 AppDomain 数量没有硬性限制)。每个 AppDomain 都有自己的 Loader 堆，每个 Loader 堆都记录了自 AppDomain 创建以来已访问过哪些类型。Loader 堆中的每个类型对象都有一个方法表，方法表中的每个记录项都指向 JIT 编译的本机代码

![](pic/22-1.png)

除此之外，每个 AppDomain 都加载了一些程序集。AppDomain #1(默认 AppDomain)有三个程序集：MyApp.exe，TypeLib.dll 和 System.dll。AppDomain #2 有两个程序集：Wintellect.dll 和 System.dll。

如图 22-1 所示，两个 AppDomain 都加载了 System.dll 程序集。如果这两个 AppDomain 都使用了来自 System.dll 的一个类型，那么两个 AppDomain 的 Loader 堆会为相同的类型分别分配一个类型对象；类型对象的内存不会由两个 AppDomain 共享。另外，一个 AppDomain 中的代码调用一个类型定义的方法时，方法的 IL 代码会进行 JIT 编译，生成的本机代码单独与每个 AppDomain 关联，而不是由调用它的所有 AppDomain 共享。

不共享类型对象的内存或本机代码显得有些浪费。但 AppDomain 的设计宗旨就是提供隔离；CLR 要求在卸载某个 AppDomain 并释放其所有资源时不会影响到其他任何 AppDomain。复制 CLR 的数据结构才能保证这一点。另外，还保证多个 AppDomain 使用的类型在每个 AppDomain 中都有一组静态字段。

有的程序集本来就要由多个 AppDomain 使用。最典型的例子就是 MSCorLib.dll。该程序集包含了 System.Object，System.Int32 以及其他所有与 .NET Framework 密不可分的类型。CLR 初始化，该程序集会自动加载，而且所有 AppDomain 都共享该程序集中的类型。为了减少资源消耗，MSCorLib.dll 程序集以一种“AppDomain 中立”的方式加载。也就是说，针对以“AppDomain 中立”的方式加载的程序集，CLR 会为它们维护一个特殊的 Loader 堆。该 Loader 堆中的所有类型对象，以及为这些类型定义的方法 JIT 编译生成的所有本机代码，都会由进程中的所有 AppDomain 共享。遗憾的是，共享这些资源所获得的收益并不是没有代价的。这个代价就是，以 “AppDomain 中立”的方式加载的所有程序集永远不能卸载。要回收它们占用的资源，唯一的办法就是终止 Windows 进程，让 Windows 去回收资源。

----------------

# 跨AppDomain通信

三种封送情况
- 按引用封送
- 按值封送
- 不可封送

## 按引用封送
源 AppDomain 想向目标 AppDomain 发送或返回对象引用时，CLR 会在目标 AppDomain 的Loader 堆中定义一个代理类型。代理类型是用原始类型完全一样；有完全一样的实例成员(属性、事件和方法)。但是，实例字段不会成为(代理)类型的一部分。代理类型确实定义了几个(自己的)实例字段，但这些字段和原始类型的不一致。相反，这些字段只是指出哪个 AppDomain “拥有”真实的对象，以及如何在拥有(对象的)AppDomain 中找到真实的对象。(在内部，代理对象用一个 GCHandle 实例引用真实的对象）

在目标 AppDomain 中定义好这个代理类型之后，CreateInstanceAndUnwrap 方法就会创建代理类型的实例，初始化它的字段来标识源 AppDomain 和真实对象，然后将对这个代理对象的引用返回给目标 AppDomain。CLR 一般不允许将一个类型的对象转换成不兼容的类型。但在当前这种情况下，CLR 允许转型，因为新类型具有和原始类型一样的实例成员。事实上，用代理对象调用 GetType，它会向你撒谎，说自己是一个MarshalByRefType 对象。

但可以证明从 CreateInstanceAndUnwrap 返回的对象实际是对代理对象的引用。为此，应用程序调用了 System.Runtime.Remoting.RemotingService 的公共静态 IsTransparentProxy 方法并向其传递 CreateInstanceAndUnwrap 方法返回的引用。从输出结果可知，IsTransparentProxy 方法返回 true，证明返回的是代理。

应用程序使用代理调用方法。由于变量引用代理对象，所以会调用由代理实现的方法。代理的实现利用代理对象中的信息字段，将调用线程从默认 AppDomain 切换至新 AppDomain。现在，该线程的任何行动都在新 AppDomain 的安全策略和配置设置下运行。线程接着使用代理对象的 GCHandle 字段查找新 AppDomain 中的真实对象，并用真实对象调用真实的 方法。

由于新创建的 AppDomain 中没有根，所以代理引用的原始对象可以被垃圾回收。这当然不理想。但另一方面，假如将原始对象不确定地留在内存中，代理可能不再引用它，而原始对象依然存活；这同样不理想。CLR 解决这个问题的办法是使用一个“租约管理器”(lease manager)。一个对象的代理创建好之后，CLR 保持对象存活 5 分钟。5 分钟内没有通过代理发出调用，对象就会失效，下次垃圾回收会释放它的内存。每发出一次对对象的调用，“租约管理器”都会续订对象的租期，保证它在接下来的 2 分钟内在内存中保持存活。在对象过期后试图通过代理调用它，CLR 会抛出 System.Runtime.Remoting.RemotingException 异常。

默认的 5 分钟和 2 分钟租期设定是可以修改的，重写 MarshalByRefObject 的虚方法 InitializeLifetimeService 即可。详情参见文档的“生存期租约”主题。


## 按值封送
当需要进行封送的实例并非是MarshalByRefObject 的派生类的实例，并且该对象可以进行序列化和反序列化时(使用[Serializable]进行标记)。就会进行按值封送
源 AppDomain 想向目标 AppDomain 发送或返回一个对象引用时，CLR 将对象的实例字段序列化成一个字节数组。字节数组从源 AppDomain 复制到目标 AppDomain。然后，CLR 在目标 AppDomain 中反序列化字节数组，这会强制 CLR 将定义了“被反序列化的类型”的程序集加载到目标 AppDomain 中(如果尚未加载的话)。接着，CLR 创建类型的实例，并利用字节数组中的值初始化对象的字段，使之与源对象中的值相同。换言之，CLR 在目标 AppDomain 中精确复制了源对象。

至此，源 AppDomain 中的对象和目标 AppDomain 中的对象就有了独立的生存期，它们的状态也可以独立地更改。如果源 AppDomain 中没有保持对象存活，源对象的内存就会在下次垃圾回收时被回收。

`跨越 AppDomain 边界封送一个 String 对象时， CLR 只是跨越边界传递对 String 对象的引用；不会真的生成 String 对象的副本。之所以能提供这个优化，是因为 String 对象是不可变的；所以，一个 AppDomain 中的代码不可能破坏 String 对象的字段`

## 不可封送
如果需要进行封送的实例并非是MarshalByRefObject 的派生类的实例，并且该实例的类型没有被标识为可序列化，那么在默认 AppDomain 中抛出一个 SerializationException 异常。


---------------

# AppDomain 卸载

AppDomain 很强大的一个地方就是可以卸载它。卸载 AppDomain 会导致 CLR 卸载 AppDomain 中的所有程序集，还会释放 AppDomain 的 Loader 堆。卸载 AppDomain 的办法是调用 AppDomain 的静态 Unload 方法。这导致 CLR 执行一系列操作来得体地卸载指定的 AppDomain。

1. CLR 挂起进程中执行过托管代码的所有线程。
2. CLR 检查所有线程栈，查看哪些线程正在执行要卸载的 AppDomain 中的代码，或者哪些线程会在某个时候返回至要卸载的 AppDomain。任何栈上有要卸载的 AppDomain，CLR 都会强迫对应的线程抛出一个 ThreadAbortException(同时恢复线程的执行)。这将导致线程展开(unwind)，并执行遇到的所有finally 块以清理资源。如果没有代码捕捉 ThreadAbortException，它最终会成为未处理的异常，CLR会“吞噬”这个异常：线程会终止，但进程可继续运行。这是很特别的一点，因为对于其他所有未经处理的异常，CLR 都会终止进程。
3. 当第 2 步发现的所有线程都离开 AppDomain 后，CLR 遍历堆，为引用了“由已卸载的 AppDomain 创建的对象”的每个代理对象都设置一个标志(flag )。这些代理对象现在知道它们引用的真实对象已经不在了。现在，任何代码在无效的代理对象上调用方法都会抛出一个 AppDomainUnloadedException异常。
4. CLR强制垃圾回收，回收由已卸载的 AppDomain 创建的任何对象的内存。这些对象的 Finalize 方法被调用，使对象有机会正确清理它们占用的资源。
5. CLR 恢复剩余所有线程的执行。调用 AppDomain.Unload 方法的线程将继续运行；对 AppDomain.Unload 的调用是同步进行的。。


`当一个线程调用 AppDomain.Unload 方法时，针对要卸载的 AppDomain 中的线程， CLR 会给它们 10 秒钟的时间离开。10 秒钟后，如果调用 AppDomain.Unload 方法的线程还没有返回，CLR 将抛出一个 CannotUnloadAppDomainException 异常，AppDomain 将来可能会、也可能不会卸载。`

`如果调用 AppDomain.Unload 方法的线程不巧在要卸载的 AppDomain 中，CLR 会创建另一个线程来尝试卸载 AppDomain。第一个线程被强制抛出 ThreadAbortException 并展开(unwind)。新线程将等待 AppDomain 卸载，然后新线程会终止。如果 AppDomain 卸载失败，新线程将抛出 CannotUnloadAppDomainException 异常。但是，由于我们没有写由新线程执行的代码，所以无法捕捉这异常`

--------------------------

# AppDomain 异常通知机制
每个 AppDomain 都可关联一组回调方法；CLR 开始查找 AppDomain 中的 catch 块时，这些回调方法将得以调用。可用这些方法执行日志记录操作。另外，宿主可利用这个机制监视 AppDomain 中抛出的异常。回调方法不能处理异常，也不能以任何方式“吞噬”异常(装作异常没有发生)；它们只是接收关于异常发生的通知。要登记回调方法，为 AppDomain 的实例事件 FirstChanceException 添加一个委托就可以了。

下面描述了 CLR 如何处理异常：异常首次抛出时，CLR 调用向抛出异常的 AppDomain 登记的所有 FirstChanceException 回调方法。然后，CLR 查找栈上在同一个 AppDomain 中的任何 catch 块。有一个 catch 块能处理异常，则异常处理完成，将继续正常执行。如果 AppDomain 中没有一个 catch 块能处理异常，则 CLR 沿着栈向上来到调用 AppDomain，再次抛出同一个异常对象(序列化和反序列化之后)。这时感觉就像是抛出了一个全新的异常，CLR 调用向当前 AppDomain 登记的所有 FirstChanceException 回调方法。这个过程会一直持续，直到抵达线程栈顶部。届时如果异常还未被任何代理处理，CLR 只好终止整个进程。



-------------------


# AppDomain 监视

宿主应用程序可监视 AppDomain 消耗的资源。有的宿主根据这种信息判断一个 AppDomain 的内存或 CPU 消耗是否超过了应有的水准，并强制卸载一个 AppDomain。还可利用监视来比较不同算法的资源消耗情况，判断哪一种算法用的资源较少。由于 AppDomain 监视本身也会产生开销，所以宿主必须将 AppDomain 的静态 MonitoringEnabled 属性设为 true，从而显式地打开监视。监视一旦打开便不能关闭；将 MonitoringEnabled 属性设为 false 会抛出一个 ArgumentException 异常。

监视打开后，代码可查询 AppDomain 类提供的以下 4 个只读属性。

- MonitoringSurvivedProcessMemorySize 这个 Int64 静态属性返回由当前 CLR 实例控制的所有 AppDomain 使用的字节数。这个数字只保证在上一次垃圾回收时是准确的。

- MonitoringTotalAllocatedMemorySize 这个 Int64 实例属性返回特定 AppDomain 已分配的字节数。这个数字只保证在上一次垃圾回收时是准确的。

- MonitoringSurvivedMemorySize 这个 Int64 实例属性返回特定 AppDomain 当前正在使用的字节数。这个数字只保证在上一次垃圾回收时是准确的。

- MonitoringTotalProcessorTime 这个 TimeSpan 实例属性返回特定 AppDomain 的 CPU 占用率。