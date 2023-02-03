# Unity 编辑器拓展


## 相关博客链接
[Unity3D编辑器插件扩展和组件扩展](https://www.cnblogs.com/rond/p/7652624.html)
[Unity编辑器图标](https://github.com/nukadelic/UnityEditorIcons)
[Unity开源的CSharp部分，可在其中找到自己想要实现的Editor样式源码](https://github.com/Unity-Technologies/UnityCsReference)
[博主营地 | 万字长文，手把手带你入门Unity拓展编辑器](https://mp.weixin.qq.com/s/96N9NkQPFhgNBeEbV_S5wg)


## 编辑器拓展需求
编辑器拓展需求一般分为三类
- **自定义Inspector** ：一般通过`Editor.OnInspectorGUI`或者是`Editor.CreateInspectorGUI`实现，后者可以通过读取一个Uxml文件来创建Inspector布局
- **自定义ScenseView**：一般通过`Editor.OnScenseGUI`方法或者是`MonoBehaviour.OnDrawGizmos`来实现。后者在场景中绘制的控件或一直显示，前者当没有点击该Object的时候就不会显示。
- **自定义Window**：一般通过`EditorWindow`或者是`ScriptableWizard`来实现。



场景更新时，editor的更新
*Normally, a player loop update will occur in the editor when the Scene has been modified. This method allows you to queue a player loop update regardless of whether the Scene has been modified.
When the Scene is modified it forces a repaint of any window that has autoRepaintOnSceneChange set to true. Additionally, the player loop will run and consequently update any scripts that are marked with ExecuteInEditMode or MonoBehaviours that have runInEditMode set to true.
Sometimes you may want more consistent updates even when the Scene has not been modified, so you can call this method to queue an update.
*