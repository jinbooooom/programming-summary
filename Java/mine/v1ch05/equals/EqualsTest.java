import core.*;

/**
 * This program demonstrates the equals method.
 * @version 1.12 2012-01-26
 * @author Cay Horstmann
 */

 /**
  * object默认的equals方法（即==）检测对象的引用：如果引用相等，那么对象肯定相等。
  * 但经常基于状态检测对象的相等性，比如判断某些字段的值是否相等。
  * 因此要实现自己的equals方法，在./core/下
  */
public class EqualsTest
{
   public static void main(String[] args)
   {
      var alice1 = new Employee("Alice Adams", 75000, 1987, 12, 15);
      var alice2 = alice1;
      var alice3 = new Employee("Alice Adams", 75000, 1987, 12, 15);
      var bob = new Employee("Bob Brandson", 50000, 1989, 10, 1);

      System.out.println("alice1 == alice2: " + (alice1 == alice2));

      System.out.println("alice1 == alice3: " + (alice1 == alice3));

      // 覆盖了超类object 的 equals 方法
      System.out.println("alice1.equals(alice3): " + alice1.equals(alice3));

      System.out.println("alice1.equals(bob): " + alice1.equals(bob));

      // 覆盖了超类object 的 toString 方法
      System.out.println("bob.toString(): " + bob);

      var carl = new Manager("Carl Cracker", 80000, 1987, 12, 15);
      var boss = new Manager("Carl Cracker", 80000, 1987, 12, 15);
      boss.setBonus(5000);
      System.out.println("boss.toString(): " + boss);
      System.out.println("carl.equals(boss): " + carl.equals(boss));
      System.out.println("alice1.hashCode(): " + alice1.hashCode());
      System.out.println("alice3.hashCode(): " + alice3.hashCode());
      System.out.println("bob.hashCode(): " + bob.hashCode());
      System.out.println("carl.hashCode(): " + carl.hashCode());
   }
}
