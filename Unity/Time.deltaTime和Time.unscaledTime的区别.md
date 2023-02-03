[TOC]
# Unity 中的时间
-----------
Unity 中的时间分为两类，一类是经过**Scale**的时间，一类是**unScale**的时间。经过**Scale**后，该时间反映的是游戏中的时间，而没有经过**Scale** 的时间反映的是实际的时间。游戏中的时间是通过[`Time.timeScale`](https://docs.unity3d.com/2019.4/Documentation/ScriptReference/Time-timeScale.html) 来进行设置的。

- 当希望功能受游戏时间影响的时候，使用**scale**类的时间，例如子弹时间，加速游戏进程等等。
- 当希望功能不受游戏时间影响的时候，使用**unScale**类的时间。例如游戏暂停后摄像机仍然可以移动。

