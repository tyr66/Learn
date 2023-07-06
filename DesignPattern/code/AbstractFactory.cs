using System;


namespace DesignPattern
{
    public interface ITouch
    {
        float x{get;}
        float y{get;}
    }

    public interface IKeyboard
    {
        char key{get;}
        void show();
        void Hide();
    }

    public interface IAccelerometer
    {
        float x{get;}
        float y{get;}
        float z{get;}
    }

    public class IOSTouch : ITouch
    {
        public float x {get{return 0;}}
        public float y {get{return 0;}}
    }

    public class IOSKeyboard:IKeyboard
    {
        public char key{get{return ' ';}}
        public void show(){Console.WriteLine("IOS KEYBOARD");}
        public void Hide(){}
    }

    public class IOSAccelerometer : IAccelerometer
    {
        public float x{get{return 0;}}
        public float y{get{return 0;}}
        public float z{get{return 0;}}
    }

    public class AndroidTouch : ITouch
    {
        public float x {get{return 0;}}
        public float y {get{return 0;}}
    }

    public class AndroidKeyboard:IKeyboard
    {
        public char key{get{return ' ';}}
        public void show(){Console.WriteLine("ANDROID KEYBOARD");}
        public void Hide(){}
    }

    public class AndroidAccelerometer : IAccelerometer
    {
        public float x{get{return 0;}}
        public float y{get{return 0;}}
        public float z{get{return 0;}}
    }

    public interface IFactory
    {
        ITouch CreateTouch();
        IKeyboard CreateKeyboard();
        IAccelerometer CreateAccelerometer();
    }

    public class IOSFactory: IFactory
    {
        public ITouch CreateTouch() {return new IOSTouch();}
        public IKeyboard CreateKeyboard() {return new IOSKeyboard();}
        public IAccelerometer CreateAccelerometer() {return new IOSAccelerometer();}
    }

    public class AndroidFactory: IFactory
    {

        public ITouch CreateTouch() {return new AndroidTouch();}
        public IKeyboard CreateKeyboard() {return new AndroidKeyboard();}
        public IAccelerometer CreateAccelerometer() {return new AndroidAccelerometer();}
    }

    public class AbstactFactory
    {
        static private string platform = "IOS";

        static public IFactory CreateFactory()
        {
            if (platform == "IOS") {
                return new IOSFactory();
            } else 
                return new AndroidFactory();
        }

        static public IFactory CreateFactoryByReflect()
        {
            string typename = "DesignPattern." + platform + "Factory";
            // Console.WriteLine("typename = " + typename);
            Type type = Type.GetType(typename);
            return Activator.CreateInstance(type) as IFactory;
        }

        static public void Test()
        {
            var factory =CreateFactoryByReflect();

            var keyboard = factory.CreateKeyboard();
            keyboard.show();
        }
    }


}
