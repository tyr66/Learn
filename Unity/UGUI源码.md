# UGUI 组件的继承层次

```
MonoBehaviour 
    ← UIBehaviour 
        ← EventSystem 
        ← BaseInput 
        ← BaseInputModule 
            ← PointerInputModule 
                ← StandaloneInputModule 
        ← BaseRaycaster 
            ← GraphicRaycaster 
            ← PhysicsRaycaster 
                ← Physics2DRaycaster 
        ← Graphic 
            ← MaskableGraphic 
                <- Image 
                <- RawImage 
                <- Text 
        ← Selectable 
            ← Button 
            ← Dropdown 
            ← InputField 
            ← Scrollbar 
            ← Slider 
            ← Toggle 
        ← ScrollRect 
        ← ToggleGroup 
        ← BaseMeshEffect 
            ← Shadow 
                ← Outline 
            ← PositionAsUV1 
```