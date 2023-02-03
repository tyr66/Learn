[TOC]
# Unity 的资源管理


## Unity 文件目录解析

--------------

### 1.1 Unity 工程目录文件夹解析
- **Asset文件夹**
  - 主要保存Unity工程实际的资源目录，所有项目用到的资源、代码、配置、库等等原始资源只有放置在这个文件夹才会被Unity认可和处理。
- **Library文件夹**
  - 存放Unity处理完毕的资源，大部分的资源导入到Assets目录之后，还需要通过Unity转化成Unity内部处理的格式，转化后的文件会存储在这个目录下的。当我们切换平台的时候资源也会被重新导入。
- **Packages文件夹**
  - Unity2018新增的，用于管理Unity分离的packages组件，Unity自动生成的C#project是不能直接对这里进行管理和修改的。同时，Unity的引擎在工作目录里也是没法对它进行操作的，是一个只读的目录。
  - 该文件夹只保存项目中使用到的packages相关信息的文件，具体的packages中对应的数据文件，则保存到Library文件夹(*在其中的PackageCache文件夹中*)中。
- **Project Setting文件夹**
  - 该目录用于存放Unity的各种项目设定
- **obj 文件夹**
  - 当你的工程开始有脚本文件的时候，Unity就会创建一个obj的目录用于代码编译

### 1.2 Asset 下的特殊目录
 - **Editor**
   - 这个目录其实是用来辅助开发的，可以是一个，也可以有很多个，可以在任意的子目录下面。主要作用就是可以编译Unity编辑器模式下提供的脚本和接口，用于辅助研发，创建各种资源检查，生成工具，以及自定义Unity的工具栏，窗口栏等等。Editor目录下的所有脚本都不会被编译到正式发行包里，很多很多优秀的插件都是需要通过Unity提供的编辑器下的扩展接口来实现功能扩展的。
 - **Editor Default Resources**
   - 该目录需要和Editor 配合使用。一个扩展面板或者工具光秃秃的也不好看，配上一些美化资源之后会让你的插件或者工具格局更高。要注意的是，这个目录只能是唯一的，并且只能放在Assets的根目录下。
- **Plugins**
  - 这个目录是存放代码之外的库文件的。比如引入的第三方代码，SDK接入的各种jar包，.a文件，.so文件.framwork文件等等，这些库文件会在Unity编译的时候链接到你的dll里。
- **Resources**
  - 和Editor一样，可以在Assets下的任何目录下，并且可以有任意多份。构建项目的时候，所有的Resources目录下的文件会被合并为一个序列化文件。该文件会有自己的metadata信息和索引信息。内部用红黑树实现资源查找，用于索引相应的File GUID和Local ID，并且它还要记录在序列化文件中的偏移量。在应用程序开始的时候Unity会加载该红黑树便于后续资源的查找
- **Gizmos**
  - 这个目录其实比较简单，就是可以辅助你在Unity的Scene视窗里显示一些辅助标线，图标或者其他的标识，用来辅助开发定位资源
- **StreamingAssets**
  - 这个文件是Unity的一个重要文件。Unity发布程序或者游戏，资源随包出去的时候，只有2个地方，一个就是Resources目录，另外一个就是StreamingAssets。这个目录的资源，文件或者任何东西，都会原封不动的复制到最终的Apk或者IOS的包内

### 1.3 Unity 项目迁移
根据上面的Unity文件目录的分析，当你的工程开始有脚本文件的时候，还会增加一个obj的目录用于代码编译。所以当你要迁移一个工程，或者将工程复制给别人的时候，只需要将Assets 、Packages以及ProjectSettings三个目录备份即可，至于Library会在Unity打开的时候进行检查和自动转化。当然如果你的工程非常庞大，资源非常多，那么迁移的时候连Library一起拷贝传递会节省大量的转化时间。

-----------------------

## Unity对脚本文件的处理

### MonoScript
MonoBehaviour的结构其实非常的简单，它内部有一个MonoScript的引用，MonoScritp里面保存有所需要的脚本的类名，程序集名，名称空间名。 **MonoBehaviour内部其实不包含任何的代码。**


### 脚本文件处理流程

- 在构建项目的时候，Unity 会将那些在**Plugins**文件夹外的脚本文件进行编译，将这些脚本编译到**Assembly-CSharp.dll**程序集中。
- 在构建项目的时候，Unity 会将在 **Plugins**文件夹中的脚本编译到**Assembly-CSharp-firstpass.dll**程序集中。
- 对于程序集来说Unity会在程序开始的时候将他们全部加载。


*除了上述的步骤外我们也可以自行的管理程序集。*
[custom managed assemblies.](https://docs.unity3d.com/Manual/ScriptCompilationAssemblyDefinitionFiles.html?_ga=2.226793951.357540566.1612425499-1832612429.1610787384)



--------------

## 2.资源的类型

Unity的Asset也是一样，我们把一个Asset叫做一个资产，可以理解为Unity能够识别的文件。这里其实又包含两种类型，一种是Unity原生支持的格式(UnityEngine.Object)，比如材质球；一种是需要经过Unity处理之后才能支持的，比如 FBX。对于需要处理才能支持的格式，Unity都提供了导入器（Importer）

unity 将游戏开发中使用到的文件分为如下几类
- **资源文件**
  - 一般指FBX文件，贴图文件，音频文件，视频文件，动画文件等等。
- **代码文件**
  - 代码文件包括所有的代码文件、代码库文件、Shader文件等。
- **序列化文件**
  - 序列化文件通常是指Unity能够序列化的文件，一般是Unity自身的一些类型，比如Prefab(预制体)、Unity3d(场景)文件、Asset(ScriptableObject)文件、Mat文件(材质球)，这些文件能够在运行时直接反序列化为对应类的一个实例。
- **文本文件**
  - 例如txt文件，xml文件，文本文档比较特殊，它不是序列化文件，但是Unity可以识别为TextAsset。很像资源文件，但是又不需要资源文件那样进行设置和转化。
- **非序列化文件**
  - 非序列文件是Unity无法识别的文件，比如一个文件夹也会被认为是一个文件，但是无法识别。
- **Meta文件**
    - meta文件的作用主要有两个，一个是起到存储资源文件的ImportSetting数据，还有是定义在它同目录下，同名的非Meta文件的唯一ID **GUID**

### Unity 内部对资源的分类
观察如下所示的`.meta`文件
```
--- !u!21 &2100000
Material:
  serializedVersion: 6
  m_ObjectHideFlags: 0
  m_PrefabParentObject: {fileID: 0}
  m_PrefabInternal: {fileID: 0}
  m_Name: mat_black256
  m_Shader: {fileID: 46, guid: 0000000000000000f000000000000000, type: 0}

m_SavedProperties:
    ...
    - first: name: _MainTex
      second:
        m_Texture: {fileID: 2800000, guid: c257c96cd50ad4ae6af2ac48a37e9e34, type: 3}
        m_Scale: {x: 1, y: 1}
        m_Offset: {x: 0, y: 0}
```


观察 `m_Texture: {fileID: 2800000, guid: c257c96cd50ad4ae6af2ac48a37e9e34, type: 3}` 这行代码，看上下文我们大概能知道这是材质mat_black256.mat的_MainTex属性引用了一张贴图,该贴图的GUID 为`c257c96cd50ad4ae6af2ac48a37e9e34` ，LocalID为 `2800000`。我们看到最后有一个type：3，这个是什么意思？这其实表示资产的类型。对于Unity来讲，资产只有4种类型
```
struct FileIdentifier { 
  enum 
  { 
    kNonAssetType = 0,
    kDeprecatedCachedAssetType = 1,
    kSerializedAssetType = 2,
    kMetaAssetType = 3 
  };
}
```

- kNonAssetType, 内置资产。这些资产guid都是0，得通过路径(path)直接找到
- kDeprecatedCachedAssetType,不知道，源码没有一个地方在用。
- kSerializedAssetType, 如果unity的数据会直接侵入式地存进资产本体，那么就是这个类型，比如 scene,prefab,material,animationclip
- kMetaAssetType,如果unity的数据不会侵入式地存进资产本体，而是在同级目录下生成一个同名的.meta文件，并且相关的配置数据都存在.meta里面。就是这个类型。比如fbx,texture

-------------------

## 3.资源的导入

### 3.1 GUID
GUID 是用来唯一标注一个资源文件，每一个资源文件都有自己的一个GUID。这个GUID是由Unity根据内部算法自动生成的，并且存放在原始文件的同目录、同名但是后缀为.meta的文件里。在编辑器中使用`AssetDatabase.GUIDToAssetPath` 和 `AssetDatabase.AssetPathToGUID` 进行互转。

**这里需要注意几个点：**
- 第一次导入资源的时候Unity会自动生成。
- 在Unity的面板里移动位置，Unity会自动帮你同步.meta文件。
- 在Unity打开的情况下，单独删除.meta，Unity可以确保重新生成的GUID和现有的一样。
- 在Unity关闭的情况下，移动或者删除.meta文件，Unity无法恢复到原有的GUID，也就是说引用会丢失。


### 3.2 LocalID
LocalID是一个对象在一个文件的唯一标识符，在通过GUID确定了资产文件位置之后，还需要一个Local IDs来定位目标Objects在资产里的位置。这样就可以通过二者的组合去快速找到对应的目标Object(例如某个Gameobject中的Transform对象)。LocalID在另一个文件中，可能会重复。 所以LocalID是一个对象在一个文件内的唯一标识符。

**LocalID的存放位置**
- 对于资源文件，非序列化文件，由于一般不会去更改源文件，所以FileID存储在meta文件中。
- 对于序列化文件，自身数据里面会存储自身的FileID，也会记录所有子文件的FileID

### Unity编辑器维护映射表
Unity还在内部维护了一张资产GUID和路径的映射表，每当有新的资源进入工程，或者删除了某些资源。又或者调整了资源路径，Unity的编辑器都会自动修改这张映射表以便正确的记录资产位置。所以如果.meta文件丢失或者重新生成了不一样的GUID的话，Unity就会丢失引用，在工程内的表现就是某个脚本显示“Missing”,或者某些贴图材质的丢失导致场景出现粉红色。

[Unity文件、文件引用、Meta详解](https://blog.uwa4d.com/archives/USparkle_inf_UnityEngine.html)

### 导入过程
1. 首先Unity 会识别你的资源的类型然后调用对应的Importer来进行资源的导入。
2. Importer 会将资源转换为对应的Unity内部能识别的格式，然后保存到Unity 工程文件夹下的 "Library/Artifacts/[xx]" 文件夹中的以该GUID前两位命名的文件中。
3. 然后Unity 会在该资源的目录下创建一个和该资源同名的.meta文件。
4. 在GUID和文件路径的映射表添加新的表项。

[Unity的资源导入过程](https://docs.unity3d.com/2019.4/Documentation/Manual/ImportingAssets.html)

--------------



## Unity对象的实例化

### Unity对象 UnityEngine.Object
Unity引擎内部使用的类型大部分都继承自UnityEngine.Object，例如Transform，Mesh，Sprite，AudioSource等等。这些类型基本都是UnityEngine.Object基类的子类，如下图所示。它们实例化出来的对象基本都可以被Unity进行序列化存储。

![](/pic/资源管理/UnityObject继承层次.png)

### 特殊的Object类型
几乎所有的类型都是内建的，其中有两种比较特殊的类型。

- **ScriptableObject** 为开发者提供了一套便捷的系统，供开发者自定义数据类型。这些类型可以被Unity直接序列化或反序列化，并在Unity编辑器的检视器窗口中进行操作。
- **MonoBehaviour** 内部有一个MonoScript的引用。MonoScript是一种内部数据类型，Unity用它保存对某个特定程序集和命名空间中特定脚本类的引用，MonoScript本身不包含任何实际的可执行代码。

### Instance ID

首先所有继承自底层Object类型的对象，都会有InstanceID。InstanceID可以理解为在内存状态的时候一个对象的指针。InstanceID在源码里面又叫HeapID,MemoryID，Instance ID表面上只是一个整数

InstanceID分为两种，一种是从-1开始往下减少的。这些对象是在运行时直接实例化的对象。另一种是从1开始往上增加的，这些对象是在运行时从磁盘加载出来实例化的对象。

程序运行的时候会有一个地方存储InstanceID到guid和LocalID的互相映射，这样就可以把一个对象从文本状态和内存状态统一起来。 这个地方叫PersistentManager.Remapper它的形式类似于下面
```Csharp
class Remapper { 
  SerializedObjectToInstanceIDMap m_SerializedObjectToInstanceID; InstanceIDToSerializedObjectMap m_InstanceIDToSerializedObject; 
  };
```

PersistentManager会维护Instance ID和File GUID 、Local ID的映射关系，定位Object源数据的位置以及维护内存中（如果有的话）Object的实例。只要系统解析到一个 Instance ID，就能快速找到代表这个Instance ID的已加载的对象。如果Object没有被加载的话，File GUID 和 Local ID也可以快速的定位到指定的资源从而即时进行资源加载。

----------------

## UnityEngine.Object 的加载和卸载

### UnityEngine.Object的加载过程

- 当Unity的应用程序启动的时候，PersistentManager的缓存系统会对项目立刻要用到的数据（比如启动场景里的这些或者它的依赖项），以及所有包含在Resources 目录的Objects进行初始化(只是初始化并不是加载具体的资源)。如果在运行时导入了Asset或者从AssetBundles（比如远程下载下来的）加载Object都会产生新的Instance ID。
- 当想要获取某个Object的时候，如果该Object已经存在在内存中就直接返回。
- 当想要获取某个Object的时候，如果Object未被加载到内存中。只有**同时满足下列两个条件的时候该Object才会被加载到内存**
  - Instance ID引用了一个没有被加载的对象。
  - 实例ID在缓存中存在对应的有效GUID和Local ID。

- 当想要获取某个Object的时候，Object当前未被加载到内存中。且该Object在缓存中对应的GUID和LocalID 已经失效。则引用本身会被保留，但实际Object不会被加载。在Unity编辑器中表现为空引用，对于贴图来说会出现粉红色。

-------------------------------

### UnityEngine.Object的卸载过程

对象被卸载有以下三种情况：

- 闲置资源清理进程开始后，一些对象会被自动卸载。该过程通常会在切换场景且不保留原场景（例如调用了非叠加的场景切换API Application.LoadLevel），或者脚本中调用了Resources.UnloadUnusedAssets时自动触发。该进程仅卸载没有被引用的对象：对象仅在Mono变量不存在对其的引用，且不存在引用该对象的其他活动对象时被卸载。**注意任何被标记为HideFlags.DontUnloadUnusedAsset或者是HideFlags.HideAndDontSave的对象都不会在该过程中被卸载**
- Resources目录中的对象可以通过调用Resources.UnloadAsset API主动卸载。卸载后对象的Instance ID会保持可用状态，对GUID和FileID的映射会被保留且仍然有效。如果有Mono变量或其他有指向该对象的活动对象引用了被Resources.UnloadAsset卸载的对象，则该对象会在任意有效的引用被解引用时立刻重新加载。
- 调用AssetBundle.Unload(true) API时，从AssetBundle中加载的对象会被立刻自动卸载。该操作会使对象Instance ID对应的GUID和LocalID无效化，任何对卸载对象的引用都会变成**空引用**。
- 如果调用了AssetBundle.Unload(false)，从被卸载的AssetBundle中仍然处于激活状态的对象不会被回收，Unity会无效其Instance ID，GUID，LocalID的缓存。之后假如它们被从内存中卸载，Unity无法再次重新加载这些对象。

[A guide to AssetBundles and Resources](https://learn.unity.com/tutorial/assets-resources-and-assetbundles#5c7f8528edbc2a002053b5a6)

-----------



## 拓展
[关于Assets,Resources和AssetBundle的讲解](https://learn.unity.com/tutorial/assets-resources-and-assetbundles#5c7f8528edbc2a002053b5a6)
[Unity 资源管理文章](https://www.cnblogs.com/zhaoqingqing/p/5825907.html)

