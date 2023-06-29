using System;

namespace DesignPattern
{
  public class Singleton
  {
    private static readonly object syncobj = new object();

    private static Singleton _instance;
    public static Singleton Instance{
      get{
        if (_instance == null) {
          lock(syncobj)
          {
            if (_instance == null)
            {
              _instance = new Singleton();
            }
          }

        }
        return _instance;
      }
    }

    private Singleton() { }

    public static void PurgeInstance()
    {
      _instance = null;
    }

    public void PrintMessage()
    {
      Console.WriteLine("printf singleton");
    }

  }

  public class TSingleton<T> where T: class, new()
  {
    static T _instance;
    private static readonly object syncobj = new object();
    public static T GetInstance()
    {
      if (_instance == null) {
        lock(syncobj)
        {
          if (_instance == null) {
            _instance = new T();
          }
        }
      }

      return _instance;
    }
  }

}
