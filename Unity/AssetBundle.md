

[TOC]
# AssetBundle

## AB包的组成
一个AssetBundle分为两个部分，
-  头部部分
	- 头部部分用来记录AB包的标识符，压缩格式，和manifest(并非manifest文件)等。manifest 包含一个查找表(在大多数的设备上是平衡二叉树，而在widnow和osx平台上是红黑树)。通过以对象名称作为索引，可以找到Unity对象在数据部分中的位置。
-  数据部分
   -  数据部分保存资源的二进制数据。

## AB包的压缩格式
AB包有三种压缩方式，如下所示
- None，不压缩，AB包中数据部分直接保存资源的二进制数据。
- LZMA，该方式对AB包数据部分进行整体压缩。
- LZ4，该方式对AB包中各个资源分别进行压缩。

AB包三种压缩方式的特点
- None，包体最大，加载最快
- LZMA，包体最小，加载最慢，在使用前需要将整体进行解压。
- LZ4，包体大小和加载速度在上面两者之间，在使用前不需要对整体进行解压，可以分块解压使用。

----------------

## AssetBundle的打包

使用BuildPipeline来进行AssetBundle打包，Unity会根据指定的平台，和指定压缩方式来生成特定的AB包。一个AB包会作为其中所有Asset的数据源(LocalID,和GUID)，unity会根据当前项目中资源的ab标签来进行AssetBundle的打包。

### 相关API
==BuildPipeline.BuildAssetBundles==

```C#
public class AssetBundleHelper {
	[MenuItem("Assets/BuildAll AssetBundle")]
    private static void BuildAllAssetBundle()
    {
        string pathName = "Assets/AssetBundle";
        if(!Directory.Exists(pathName))
        {
            Directory.CreateDirectory(pathName);
        }
        BuildPipeline.BuildAssetBundles(pathName,
                                        BuildAssetBundleOptions.None,
                                        BuildTarget.StandaloneWindows);
    }
}
```

## 加载AssetBundle

### 相关API
==AssetBundle.LoadFromMemory(存在异步版本)==

- 同步的创建一个AssetBundle，Unity不推荐使用该API，该函数的参数是(byte[])，该API的作用是从一个字节数组中加载一个AssetBundle，该API会在内部分配一个本机的连续的本机内存块，将源数据从字节数组复制到新分配的内存块中。当AB包使用LZMA压缩的时候，它会在复制的时候解压，当AB包没有压缩或者使用LZ4压缩的时候则会直接复制。

==AssetBundle.LoadFromFile== (存在异步版本)

- 从磁盘中加载AB包可以高效的加载未压缩或者是LZ4压缩的AB包，在电脑，主机，手机平台上，当AB包是未经压缩或者是LZ4压缩的话只加载AB包的头部(当需要加载AB包中的数据的时候再从磁盘中加载)，如果是加载LZMA压缩的AB包的话，会将AB包解压到内存中。 
- 在编辑器模式的时候该API会将整个AssetBundle加载进内存中，所以在编辑器中Profile的时候可能会造成峰值。这时候应该在真机上进行测试然后再判断性能。

==AssetBundleDownloadHandler==

- DownloadHandlerAssetBundle。它使用工作线程，它流式的下载数据并将其存储到一个固定大小的缓冲区中，然后根据Download Handler的配置方式将缓冲区中的数据放到临时存储或AssetBundle缓存中。如果请求的AB包已经存在于Unity的缓存中那么会直接使用已经存在的AB包。

- 所有这些操作都发生在非托管代码中，消除了增加堆内存的风险。此外，它不会保留在本机代码中的字节副本，从而进一步减少了下载AssetBundle时的内存开销。

- LZMA压缩的AB包将会在下载的过程中进行解压然后使用LZ4进行压缩后进行缓存。该行为可以通过Caching.CompressionEnabled来更改。

### 使用建议
- 一般来说，只要有可能，就应该使用AssetBundle.LoadFromFile。这个API在速度、磁盘使用和运行时内存使用方面是最高效的。
- 对于必须下载或热更新AssetBundles的项目，强烈建议对使用Unity5.3或更高版本的项目使用UnityWebRequest，对于使用Unity5.2或更老版本的项目使用WWW.LoadFromCacheOrDownload。
- 当使用UnityWebRequest或WWW.LoadFromCacheOrDownload时，要确保代码在加载AssetBundle后正确地调用UnityWebRequest对象的Dispose方法。另外，C#的using语句是确保WWW或UnityWebRequest被安全处理的最方便的方法。
- 对于需要独特的、特定的缓存或下载需求的大项目，可以考虑使用自定义的下载器。编写自定义下载程序是一项重要并且复杂的任务，任何自定义的下载程序都应该与AssetBundle.LoadFromFile保持兼容。

-------------------

## 从AssetBundle 中加载资源

### 相关API
**以下API都有异步版本，,以下所有的加载API同步版本都比异步的版本至少快一帧**

==AssetBundle.LoadAllAssets==
- 加载AB包中的所有资源或者指定的类型的所有资源,当需要从AB包中加载所有资源或者是大部分资源的时候，使用该API比分批次的使用**AssetBundle.LoadAssets**更高效。

==AssetBundle.LoadAssetWithSubAssets==
- 当加载一些内部有许多内嵌对象的复合资源的时候使用该API，例如Sprite Atlas和一些带有动画的Fbx模型等等。

==AssetBundle.LoadAsset==
- 加载指定的资源，当不符合上述两个API的使用条件的时候使用该API进行资源加载。

Object加载是在主线程上执行，但数据从工作线程上的存储中读取。任何不触碰Unity系统中线程敏感部分（脚本、图形）的工作都将在工作线程上转换。例如，VBO将从网格创建，纹理将被解压等等。
从Unity 5.3开始，Object加载就被并行化了。在工作线程上反序列化、处理和集成多个Object。当一个Object完成加载时，它的Awake回调将被调用，该对象的其余部分将在下一个帧中对UnityEngine可用。

从Unity5.3开始Object的加载就被并行化了。当一个Object成功加载后，它的Awake方法将会被调用并且该Object将会在下一帧变得可用。

--------------

## AssetBundle包依赖
当一个AB包中的一个或多个UnityEngine.Object，引用到另外一个AB包中的一个或者多个UnityEngine.Object时被称为AB包依赖。
当我们第一次创建一个AB包后，Unity会在AB包所在的文件夹中创建一个和文件夹同名的.manifest文件中，该文件本质上也是一个AB包。这个AB包是用来管理该文件夹下所有AB包的依赖信息的，所有AB包的依赖信息都保存在该AB包对应的manifest中。

### 获取AB包依赖的API

根据运行时环境的不同，使用两个不同的API自动跟踪AssetBundles之间的依赖关系。在UnityEditor中，可以通过AssetDatabaseAPI查询AssetBundle依赖项，也可以使用AssetImportAPI查询分配特定Objects的AssetBundle。在运行时，Unity提供了一个可选的API，通过AssetBundleManifest 加载和查看AssetBundle的依赖信息。


==AssetBundleManifest.GetAllAssetBundles==
- 获取和该Manifest同时构建的所有AB包的名称

==AssetBundleManifest.GetAllDependencies==
- 获取指定AB包的所有依赖,其中包括AssetBundle的直接子级、其子级的依赖项等。

==AssetBundleManifest.GetDirectDependencies==
- 获取指定AB包的直接依赖

**这三个API都会分配字符串数组，注意不要在性能敏感的时候使用**

&ensp;即使存在AB包依赖，只要加载资源的时候将所需要的AB包全部加载出来，资源就能正确的被加载。**这是因为当AB包被加载到内存中时，Unity会在缓存中为AB包和其中的所有资源生成关于InstanceID ，GUID，LocalID等信息的表项**。如下图所示

![](/pic/AssetBundle/AssetBundle.png)

假设material A引用texture B。material A被打包到AssetBundle1中，texture B被打包到AssetBundle2中，在本用例中，AssetBundle2必须在material A从AssetBundle1中加载之前先加载。这并不意味着AssetBundle 2必须在AssetBundle 1之前加载，或者texture B必须从AssetBundle 2中显式加载。在将material A从AssetBundle 1加载之前加载AssetBundle 2就足够了。

在加载对象之前，重要的是加载对象依赖的所有AssetBundles。Unity不会尝试在加载AssetBundle时自动加载任何依赖的AssetBundle。

---------------

## 卸载从AssetBundle中加载的资源

### 相关API
==AssetBundle.Unload(unloadAllLoadedObjects)==
- 当参数unloadAllLoadedObjects为true时，会将AB包和它所加载的资源全部从内存中卸载。不管其是否还在被使用 
- 当参数unloadAllLoadedObjects为false时，只会卸载对应的AB包，对于已经从该AB包中加载出来的对象会保留(但对象在缓存中的GUID和FileID已经失效)。

==Resources.UnloadUnusedAssets==
一个AB包卸载后，当其遗留的资源无引用的时候可以调用该方法来卸载。调用该方法会触发GC。

==Resources.UnloadAsset==
一个AB包卸载后，我们可以使用该API来卸载指定的残留资源。


------------


## AssetBundle 使用原则

### AssetBundle资源重复加载的问题
假设从AB包中加载了一个资源M，那么在使用AssetBundle.unLoad(false)卸载AB之后，再次加载AB并从中加载资源M，那么内存中就会有两份资源M。Unity并不会识别出之前的资源M 。而是重新加载一份新的。这就造成了内存中资源重复。

### AB包和其资源的生命周期管理
对于大多数项目来说，应该使用AssetBundle.Unload(true)并且通过一些方法来确保对象不会重复。有两种常见的方法。
- 在游戏的生命周期中分配一些特定的时间点，在这个时间点中进行AB包的卸载，例如关卡切换时。
- 为每一个独立的对象维护一个引用计数，只有当从AB包中加载出来的对象没有被引用的时候卸载对象。

如果应用程序必须使用AssetBundle.Unload(false)来卸载AB包，那么已加载的对象只有符合下列两种情况之一时才卸载。
- 在场景和代码中消除对该对象的所有引用，完成后，调用Resources.UnloadUnusedAssets。
- 非附加加载场景。这将销毁当前场景中的所有对象并调用Resources.UnloadUnusedAssets。


### AB包的发布
将AB包发布给用户由两种方式，
- 一种时在安装应用的同时安装AB包。主机或者是PC平台。
  - 减少项目构建时间并允许更简单的迭代开发。如果这些AssetBundles不需要和应用程序本身分开更新的话，可以通过将AssetBundles存储在 Streaming Assets中，将AssetBundles包含在应用程序中。
  - 发布可更新内容的初始修订版。这通常是为了节省终端用户在安装后下载内容的时间，或者作为以后修补的基础。Streaming Assets在这种情况下并不理想。
- 一种是安装之后再下载AB包。手机平台。
    - 将AssetBundles传递到移动设备的最好方法是在应用程序安装后再下载它们。这就允许在安装后再更新游戏内容，而不必强迫用户重新下载整个应用程序。在许多平台上，应用程序二进制文件必须经过昂贵而漫长的重新认证过程。因此，开发一个良好的分离下载系统是至关重要的。
    - 交付AssetBundles最简单的方法是将它们放在某个Web服务器上，并通过UnityWebRequest发布。Unity将自动在本地存储上缓存下载的AssetBundles。如果下载的AssetBundle是LZMA压缩的，那么AssetBundle将以未压缩或重新压缩的形式存储在缓存中，就像LZ 4一样(依赖Caching.compressionEnabled设置)，以便将来更快地加载。如果下载的包是LZ4压缩的，AssetBundles将被压缩存储。如果缓存被填满，Unity将从缓存中删除最近使用最少的AssetBundle。


### 自定义下载系统
通常建议在允许的情况下使用UnityWebRequest，或者只有在使用Unity5.2或更老版本时才使用WWW.LoadFromCacheOrDownload。只有当内置API的内存消耗、缓存行为或性能对于特定项目是不可接受的时候，或者项目必须运行特定于平台的代码才能满足其需求时，才需要自定义下载系统或扩展原有的系统。

需要自定义下载系统的情况
- 当需要对AssetBundle缓存进行颗粒度控制时。
- 当项目需要实现自定义压缩策略时。
- 当项目希望使用特定于平台的API来满足某些需求时，例如在不活动时才加载流数据。比如，使用IOS的后台任务API下载数据。
- 当AssetBundles必须在不具备SSL支持条件(如PC)的平台上通过SSL交付时时候。

自定义下载系统需要考虑的地方
- 下载机制
- 存储位置
- 压缩类型
- 热更

对于大多数应用来说，HTTP是下载AB包的最简单的方法，然而实现一个基于HTTP的下载器并不是一个简单的任务，自定义下载器必须避免过多的内存分配，过多的线程调用和过多的线程唤醒。Unity的WWW类是不合适的。

当实现一个下载器的时候有三个选择
- C#的HTTPWebRequest和WebClient类
  - 如果一个应用没有要求HTTPS/SSL支持，C#的WebClient 类提供了一个最简单下载AB包的机制，它能够将任何文件直接的异步下载到本地存储，而无需分配过多的托管内存。要使用WebClient下载AssetBundle，请分配该类的实例，然后将要下载的AssetBundle的URL和目标路径传递给该类。如果想要更多的控制则可以使用C＃的HttpWebRequest类编写下载程序
- 自定义的本地引用
  - 自定义的本地插件是花费时间最高和技术风险最大的方案，但是它提供了最大的灵活性。，只有当其他方案没有能力去满足应用程序需求的时候才考虑它。例如，如果应用程序必须在Unity不支持C＃SSL的平台上使用SSL通信，则可能需要自定义本机插件。自定义的本机插件一般来说会封装目标平台上的API，例如IOS上的 NSURLConnection 和Android上的java.net.HttpURLConnection。参考各个平台的本机文档来获取更多的信息。
- Asset Store的Package
  - 一些商店中的插件提供了本机代码实现，可以通过HTTP，HTTPS和其他协议下载文件。 在为Unity编写自定义本机代码插件之前，建议评估可用的Asset Store插件。


### Streaming Assets文件夹
在安装时将任何类型的内容(包括AssetBundles)包含在一个Unity应用程序里，最简单的方法是在构建项目之前将内容构建到/Asset/StreamingAsset/文件夹中。构建时StreamingAsset文件夹中包含的任何内容都将复制到最终的应用程序里。
在运行时，可以通过属性Application.StreamingAssets 访问本地存储上StreamingAsset文件夹的完整路径。然后，可以通过AssetBundle.LoadFromFile加载AssetBundles。

Streaming Assets文件夹在不同平台上有不同的位置，如下所示
- OSX：在.app包内；不可写。
- Windows : 在安装目录，一般不可写
- IOS：在.ipa包内；不可写
- Android：在.apk文件中；不可写

-------------

## Unity 内置的AB包缓存系统
**Unity 有一个内置的AB包缓存系统可以被用来缓存通过 UnityWebRequest API下载的AB包**。该UnityWebRequest API的重载会接受一个AssetBundle版本号作为参数。该版本号并不是保存在AB包中的，也不是由AssetBundle system系统生成的。
缓存系统跟踪传递给UnityWebRequest的最后一个版本号。当使用版本号调用此API时，缓存系统通过比较版本号来检查是否存在缓存的AssetBundle。如果这些数字匹配，系统将加载缓存的AssetBundle。如果数字不匹配，或者没有缓存的AssetBundle，那么Unity将下载一个新的副本。此新副本将与新的版本号相关联。
缓存系统中的AssetBundle只通过它们的文件名来标识 ，而不是通过下载它们的完整URL。这意味着具有相同文件名的AssetBundle可以存储在多个不同的位置，例如CDN。只要文件名相同，缓存系统就会将它们识别为相同的AssetBundle。

在Unity2017.1中，允许开发人员从多个缓存中选择一个活动缓存，缓存API已经被扩展成为可以提供更细颗粒度的控制了。以前的Unity 版本只能修改Caching.expirationDelay和Caching.maximumAvailableDiskSpace。
- expirationDelay是自动删除AssetBundle之前必须经过的最小秒数。如果在此期间没有访问过AssetBundle，则将自动删除它。
- MaximumAvailableDiskSpace指定缓存在开始删除最近使用的AssetBundles之前，可以使用的本地存储空间的大小(以字节为单位)。当达到限制时，Unity将删除缓存中最近打开的AssetBundle(或通过Caching.MarkAsUsed标记)。Unity会删除缓存的AssetBundle，直到有足够的空间完成新的下载为止。


### 初始化缓存
因为AssetBundles是通过它们的文件名来标识的，所以可以使用应用程序初始附带的AssetBundles来“初始化”缓存。为此，将每个AssetBundle的初始或基本版本存储在/Asset/StreamingAsset/中。在应用程序第一次运行时，可以通过从Application.streamingAssetsPath 使用UnityWebRequest API加载AssetBundles来填充缓存。

-------------

## 资源打包

我们可以根据场景来将单个场景依赖的资源打包到AB包中，那么在加载下一个场景的时候我们就可以卸载当前AB包然后直接加载下一个场景的AB包。

当决定如何将资源打包到AB包的时候，最好的方式是将需要在同一时间进行加载和更新的对象打包到同一个AB包中。例如一些地图和过场动画可以根据场景的不同被打包到AB包中。一些在多数场景都会被使用到的资源(例如，UI，角色模型，贴图等等)都可以被打包到一个AB包中，然后在游戏开始加载，在整个生命周期中都存在。



### 资源的重复打包问题
假设我们有一个Prefab，该Prefab引用了一个Material。但是这个Material并没有打到任何一个AB包中，那么此时Unity 的打包策略会将该Material拷贝，然后将副本和Prefab一起进行打包。当多个不同的AB包中都有Object引用到该Material的时候，每一个AB包内都会有该Material的一份副本。这就会增大AB包的体积。当我们从这些AB包中加载Object的时候，内存就会有多个Matrial的副本。


#### 重复打包造成的影响
它会造成如下影响
- 影响包体大小
- 可能增大了APP的体积
- 可能增大了运行时的内存消耗
- 可能会影响Unity的合批(patching)，不同AB包中Material副本会被认为是不同的Material，即使他们都是相同的material的副本


#### 解决方案
资源重复打包的问题，有如下几种解决方案。
- 将被共享的资源打包到依赖它的AB包中，但这种方案会造成AB包体积过大。
- 对AB包进行分类，这样就不会同一时间加载两个共享依赖的AB包，此方法可能适用于某些类型的项目，例如基于关卡的游戏。 但是，它仍然不必要地增加了项目的AssetBundle的大小，并增加了构建时间和加载时间。
- 让被共享的资源都打包到单独的AB包中，这样就完全消除了资源重复的风险，但会提高复杂性。我们必须确保从AB包中加载资源的时候，所需的AB包被全部加载。


通过使用AssetDatabase和AssetImportAPI，可以编写一个编辑器脚本，以确保将AssetBundle的所有直接或间接依赖项分配给另一个AssetBundles，或者查找是否存在没有没有被打包到AB包的被共享的资源。

----------------

## AssetBundle 变体
Unity AssetBundle系统的一个关键功能是AssetBundle变体，AB变体的目的是让应用程序可以调整它的内容来更好的适配运行环境。它允许多个在不同AB包中的对象共享同一个GUID和LocalID，然后通过一个变体ID来定位具体的对象。变体的使用场景如下。
例如对于高配的机械我们可以使用高分辨率的贴图和复杂的shader，对于低配的机器我们则应该使用分辨率较低的贴图和简单的shader，变体可以让我们在运行时根据平台的类型来加载不同的AB包而不用改变资源加载的代码。**变体简化了适合给定平台的AssetBundles的加载**


### 变体的限制
AssetBundle变体系统的一个关键限制是，它要求从不同的Asset构建变体。即使这些Asset之间的唯一不同是它们的导入设置，这个限制也是合理的。如果在变体A和变体B中构建的纹理之间的唯一区别是在Unity纹理导入器中选择的特定纹理压缩算法，则变体A和变体B仍然必须是完全不同的Asset。这意味着变体A和变体B必须是磁盘上的单独文件。
这一限制使大型项目的管理变得复杂，因为必须将特定Asset的多个副本保存在源代码管理中。当开发人员希望更改Asset的内容时，必须更新Asset的所有副本。对于这个问题，没有非常好的解决办法.

--------------

## AB包压缩
AB是否需要压缩需要考虑如下几个方面。
- **加载时间** ： 加载非压缩的AB包比压缩了的AB包无论是在AB缓存中或者是本地存储上都要快。
- **构建时间** : 对AB包进行压缩的过程是很慢的，况且Unity是连续的处理AB包的，如果项目有许多AB包，那么就会花费大量的时间来压缩这些AB包。
- **应用程序大小** : 如果AB包是嵌入到应用程序中来进行发布，那么压缩AB包会减少应用程序的体积。
- **内存使用** : 在Unity5.3之前，Unity的所有解压缩机制都要求在解压缩之前将整个压缩的AssetBundles加载到内存中。如果内存使用很重要，请使用未压缩或LZ4压缩AssetBundles。
- **下载时间** : 如果用户的网络条件不稳定或者时不太好的时候，压缩的AB的加载时间更少。


*主要由使用Crunch压缩算法的DXT压缩纹理组成的AB包应不需要进行压缩。*

--------------

## 补充

### Android Texture

对于安卓平台，一般需要将贴图压缩成几种不同的格式，所有的安卓设备都支持ETC1格式，但是ETC1格式不支持带有透明通道的贴图。

很多应用程序需要在不支持ETC 2的旧设备上发布。解决这个问题的一种方法是使用Unity5的AssetBundle变体

要使用AssetBundle变体，所有不能使用ETC 1进行完全压缩的纹理必须隔离到只有纹理的AssetBundles中。接下来，使用DXT 5、PVRTC和ATITC等特定供应商的纹理压缩格式，创建这些AssetBundles的足够变体，以支持Android生态系统中不具备ETC 2功能的切片。对于每个AssetBundle变体，需要包含的纹理的TextureImporter设置更改为适合该变体的压缩格式。

在运行时，可以使用SystemInfo.SupportsTextureFormatAPI检测对不同纹理压缩格式的支持。


### AB包和WebGl
在WebGL中所有AB报的解压和加载必须发生在主线程中，
WebGL项目中的所有AssetBundle解压缩和加载必须发生在主线程上，因为Unity的WebGL导出选项目前不支持工作线程。使用XMLHttpRequest将AssetBundles的下载委托给浏览器。一旦下载，压缩的AssetBundles将被解压在Unity的主线程上，因此会根据包的大小而延迟Unity内容的执行。
Unity建议开发人员用小型AssetBundles，以避免出现性能问题。与使用大型AssetBundles相比，这种方法还具有更高的内存效率。UnityWebGL只支持LZ4-压缩和未压缩的AssetBundles，但是，可以将gzip/brotli压缩应用于由Unity生成的包上。在这种情况下，您需要相应地配置Web服务器，以便在浏览器下载时解压文件。
如果您使用的是Unity5.5或更老版本，请考虑避免对AssetBundles使用LZMA，而使用LZ4进行压缩，这对按需解压缩非常有效的。Unity5.6删除了LZMA作为WebGL平台的压缩选项。



[Unity 官方教程：Assets，Resources，AssetBundle](https://learn.unity.com/tutorial/assets-resources-and-assetbundles#5c7f8528edbc2a002053b5a8)
[Unity 的memory-management](https://learn.unity.com/tutorial/memory-management-in-unity?language=en#5c7f8528edbc2a002053b599)
[Unity 的AssetBundle教程](https://learn.unity.com/tutorial/introduction-to-asset-bundles?language=en#5ce589b4edbc2a106aa7b47a)










