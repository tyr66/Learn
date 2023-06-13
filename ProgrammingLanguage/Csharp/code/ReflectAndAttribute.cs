using System.ComponentModel;
using System.Runtime.CompilerServices;
using System;
using System.Reflection;

namespace ReflectAndAttribute
{
    #region  获取数组类型
    public class GetArray
    {
        public static void Test()
        {
            var intArray = typeof(int).MakeArrayType();
            var int3Array = typeof(int).MakeArrayType(3);

            Console.WriteLine($"是否是int 数组 intArray == typeof(int[]) ：{intArray == typeof(int[])}");
            Console.WriteLine($"是否是int 数组 intArray3 == typeof(int[]) ：{int3Array == typeof(int[])}");
            Console.WriteLine($"是否是int 3维数组 intArray3 == typeof(int[,,])：{int3Array == typeof(int[,,])}");

            //数组元素的类型
            Type elementType = intArray.GetElementType();
            Type elementType2 = int3Array.GetElementType();

            Console.WriteLine($"{intArray}类型元素类型：{elementType}");
            Console.WriteLine($"{int3Array}类型元素类型：{elementType2}");

            //获取数组的维数
            var rank = int3Array.GetArrayRank();
            Console.WriteLine($"{int3Array}类型维数：{rank}");
        }
    }
    #endregion

    #region  获取Type对象
    public class GetType
    {
        public class Base {

        }
        public class Derived:Base{

        }

        public static void Test()
        {

            Derived a = new Derived();

            Type t = a.GetType();

            Console.WriteLine(t.Namespace + " " + t.Name);

            FieldInfo[] fieldInfo = t.GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static | BindingFlags.Instance);

            foreach (var field in fieldInfo)
            {
                Console.WriteLine(field.FieldType.Name + " " + field.Name);
            }
        }
    }
    #endregion

    #region 获取嵌套类型

    public class GetNestedClass
    {
        public class Derived {
            public struct Item{
                int id;
            }
        }
        public static void Test()
        {
            Type t = typeof(Derived);

            foreach (var c in t.GetNestedTypes())
            {
                Console.WriteLine($"NestedType is {c}");
            }
        }
    }

    #endregion

    #region 获取基类和接口
    public class GetBaseClassAndInterface{

        public interface MyInterface
        {
            void show(){}
        }
        public class Base:MyInterface
        {
        }
        public class Derived
        {

        }

        public static void Test()
        {
            Type t = typeof(System.String).BaseType;

            Console.WriteLine($"BaseClass is {t.FullName}");

            t = typeof(FileStream).BaseType;

            Console.WriteLine($"BaseClass is {t.FullName}");

            foreach (var v in typeof(Derived).GetInterfaces())
            {
                Console.WriteLine($"interface : {v.FullName}");
            }
        }
    }

    #endregion

    #region 类型实例化

    public class TypeInstantiate
    {
        public class Base
        {
            protected int _id;
            protected string _name;
            public Base(int id) {this._id = id; }
            public Base() { }
            public Base(string name) { this._name = name;}
            public Base(int id, string name) {this._id = id; this._name = name; }

            public void show() {
                Console.WriteLine($"Base: id = {_id}, name = {_name}");
            }
        }
        static public void Test()
        {
            Base b = (Base)Activator.CreateInstance(typeof(Base), 2, "kdf");
            b.show();

            Type t = b.GetType();
            var constructor = t.GetConstructor(new Type[]{});
            b = (Base)constructor.Invoke(new object[]{});
            b.show();

            constructor = t.GetConstructor(new Type[]{typeof(int), typeof(string)});
            b = (Base)constructor.Invoke(new object[]{1, "tyr"});
            b.show();

            ConstructorInfo[] infos = t.GetConstructors();

            constructor = Array.Find(infos, x => x.GetParameters().Length == 2 && x.GetParameters()[0].ParameterType == typeof(int) && x.GetParameters()[1].ParameterType == typeof(string));

            b = (Base) constructor.Invoke(new object[]{3, "yaorong"});
            b.show();
        }
    }
    #endregion

    #region 委托实例化
    public class DelegateInstantiate
    {
        static void staticshow(){
            Console.WriteLine("static ");
        }
        public void instanceshow() {
            Console.WriteLine("Instance");
        }
        public delegate void Show();

        static public void Test()
        {
            var staticFunc = Delegate.CreateDelegate(typeof(Show), typeof(DelegateInstantiate), "staticshow");
            var instanceFunc = Delegate.CreateDelegate(typeof(Show), new DelegateInstantiate(), "instanceshow");

            staticFunc.DynamicInvoke();
            instanceFunc.DynamicInvoke();
        }
    }
    #endregion

    #region 泛型的实例化
    public class GenericInstantiate
    {
        public static void Test()
        {
            
            Console.WriteLine(typeof(List<>));
            Console.WriteLine(typeof(List<>).MakeGenericType(typeof(int)));
            Console.WriteLine(typeof(List<int>));
            Console.WriteLine(typeof(List<int>).GetGenericTypeDefinition());
        }
    }
    #endregion
}