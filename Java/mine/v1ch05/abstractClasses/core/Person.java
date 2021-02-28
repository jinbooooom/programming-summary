//package abstractClasses;
package core;

public abstract class Person
{
   // 抽象方法不需要给任何实现
   public abstract String getDescription();
   private String name;

   public Person(String name)
   {
      this.name = name;
   }

   public String getName()
   {
      return name;
   }
}
