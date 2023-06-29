using System;

namespace DesignPattern
{
  public enum ItemType
  {
    Stuff = 0,
    Material,
    Equipment,
  }


  public abstract class Item
  {
    public int ItemID{get;set;}
    public ItemType ItemType{get;}

    protected Item(ItemType itemtype, int id){
      this.ItemID  = id;
      this.ItemType = itemtype;
    }

    public void PrintItem()
    {
      Console.WriteLine(string.Format("ItemType = {0}, ID = {1}", this.ItemType, this.ItemID));
    }
  }

  public class Stuff: Item
  {
    public Stuff(int id):base(ItemType.Stuff, id) { }
    public Stuff():base(ItemType.Stuff, -1){}
  }

  public class Material:Item
  {
    public Material(int id):base(ItemType.Material, id) { }
    public Material():base(ItemType.Material, -1){}
  }

  public class Equipment :Item
  {
    public Equipment(int id):base(ItemType.Equipment, id) { }
    public Equipment():base(ItemType.Equipment, -1) {}
  }

  public abstract class ItemFactory
  {
    abstract public Item CreateItem(int itemID);
  }

  public class MaterialFactory: ItemFactory
  {
    override public Item CreateItem(int itemID)
    {
      return new Material(itemID);
    }
  }

  public class StuffFactory: ItemFactory
  {
    override public Item CreateItem(int itemID)
    {
      return new Stuff(itemID);
    }
  }

  public class EquipmentFactory: ItemFactory
  {
    override public Item CreateItem(int itemID)
    {
      return new Equipment(itemID);
    }
  }

  public static class TFactory
  {
    public static T CreateItem<T>(int id) where T:Item, new()
    {
      T item = new T();
      item.ItemID = id;
      return item;
    }
  }

}
