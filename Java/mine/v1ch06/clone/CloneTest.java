import clone.*;

/**
 * This program demonstrates cloning.
 * @version 1.11 2018-03-16
 * @author Cay Horstmann
 */
public class CloneTest
{
   public static void main(String[] args) throws CloneNotSupportedException
   {
      var original = new Employee("John Q. Public", 50000);
      original.setHireDay(2000, 1, 1);
      // 若想要深拷贝必须继承 Cloneable 接口，并实现 clone 方法.
      // Cloneable 是Java 中提供的少数标记接口：即不包含任何方法，唯一的作用就是
      // 允许在类型查询中使用 instanceof
      Employee copy = original.clone();
      copy.raiseSalary(10);
      copy.setHireDay(2002, 12, 31);
      System.out.println("original=" + original);
      System.out.println("copy=" + copy);
   }
}
