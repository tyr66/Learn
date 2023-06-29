using System;
using DesignPattern;

public class Excute
{
  public static void Main(string[] args)
  {
    ItemFactory factory = new MaterialFactory();
    Item item = factory.CreateItem(0);
    item.PrintItem();

    item = TFactory.CreateItem<Equipment>(1);
    item.PrintItem();
  }
}
