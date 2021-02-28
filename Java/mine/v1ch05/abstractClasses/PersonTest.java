//package abstractClasses;
import core.*;

/**
 * This program demonstrates abstract classes.
 * @version 1.01 2004-02-21
 * @author Cay Horstmann
 */
public class PersonTest
{
   public static void main(String[] args)
   {
      var people = new Person[2];

      // fill the people array with Student and Employee objects
      people[0] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
      people[1] = new Student("Maria Morris", "computer science");

      // 编译不通过，因为 person 里不含有 getSalary()，【i171】
      // 编译器只允许调用在类中声明的方法，该方法是Employee专有，不能通过父类去调用子类的专有方法。
      // 但可以用一些其他的操作去做：一个C++例子，https://blog.csdn.net/qq_31244951/article/details/89386352
      // Java 可以通过反射去操作。
      // System.out.println("test: " + people[0].getSalary());

      // print out names and descriptions of all Person objects
      for (Person p : people)
         System.out.println(p.getName() + ", " + p.getDescription());
   }
}
