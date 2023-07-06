using System;

namespace DesignPattern
{
    public enum RobotPart
    {
        Leg,
        Hand,
        Head,
        Body,
    }

    public interface IHand
    {
        public void print();
    }
    public interface IHead
    {
        public void print();
    }
    public interface ILeg
    {
        public void print();
    }
    public interface IBody
    {
        public void print();
    }


    public class Robot
    {
        public IHand hand;
        public ILeg leg;
        public IHead head;
        public IBody body;

        public void print()
        {
            Console.WriteLine("Robot construct by");

            head.print(); hand.print(); body.print(); leg.print();
        }
    }

    public class BigHand : IHand
    {
        public void print()
        {
            Console.WriteLine("BigHand");
        }
    }
    public class SmallHand : IHand
    {
        public void print()
        {
            Console.WriteLine("SmallHand");
        }
    }
    public class BigLeg : ILeg
    {
        public void print()
        {
            Console.WriteLine("BigLeg");
        }
    }
    public class SmallLeg : ILeg
    {
        public void print()
        {
            Console.WriteLine("SmallLeg");
        }
    }
    public class GandaHead : IHead
    {
        public void print()
        {
            Console.WriteLine("GandaHead");
        }
    }
    public class NormalHead : IHead
    {
        public void print()
        {
            Console.WriteLine("NormalHead");
        }
    }
    public class NormalBody : IBody
    {
        public void print()
        {
            Console.WriteLine("NormalBody");
        }
    }

    public class RobotBuilder
    {
        static public object createPart(string partName)
        {
            string typename = "DesignPattern." + partName;
            Type type = Type.GetType(typename);
            return Activator.CreateInstance(type);
        }

        static public Robot Build(Dictionary<RobotPart, string> parts)
        {
            Robot robot = new Robot();
            foreach (var part in parts)
            {
                if (part.Key == RobotPart.Leg)
                {
                    robot.leg = (ILeg)createPart(part.Value);
                }
                if (part.Key == RobotPart.Hand)
                {
                    robot.hand = (IHand)createPart(part.Value);
                }
                if (part.Key == RobotPart.Body)
                {
                    robot.body = (IBody)createPart(part.Value);
                }
                if (part.Key == RobotPart.Head)
                {
                    robot.head = (IHead)createPart(part.Value);
                    ;
                }
            }

            return robot;
        }

    }
    public class GeneratorPattern
    {
        public static void Test()
        {
            Dictionary<RobotPart, string> parts = new Dictionary<RobotPart, string>();
            parts[RobotPart.Leg] = "BigLeg";
            parts[RobotPart.Hand] = "SmallHand";
            parts[RobotPart.Body] = "NormalBody";
            parts[RobotPart.Head] = "GandaHead";
            Robot robot = RobotBuilder.Build(parts);
            robot.print();
        }
    }
}
