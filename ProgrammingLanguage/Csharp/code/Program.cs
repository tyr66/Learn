using System.IO;
using System.Reflection;
using System;

using ReflectAndAttribute;

namespace Learn
{
    public class Base:ITest{
        protected int baseInt;
        public static int staticInt;
    }

    public interface ITest
    {
        void show(){}
    }

    public class Derived:Base
    {
        public class NestedClass{
            public int id;
        }
        protected int derivedInt;
    }

    class Program
    {
        static void Main(string[] args)
        {
            ReflectAndAttribute.GenericInstantiate.Test();
            Console.ReadKey();
        }

       
    }

}