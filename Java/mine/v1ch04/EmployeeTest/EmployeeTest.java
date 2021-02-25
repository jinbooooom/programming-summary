import java.time.*;
import java.util.Objects;

/**
 * final修饰
 * 关键字 final修饰可变的对象，类似于C++的顶层const：
 * 指针指向的空间内容可变，但指针本身不可变。
 */

 // 文件名必须与public类的名字相匹配。在一个文件中只能有一个公共类，但可以有任意数目的非公共类。
 // 编译时将创建两个类文件 Employee.class 和 EmployeeTest.class
 // 【i106,107】编译过程
public class EmployeeTest
{
   public static void main(String[] args)
   {
      // fill the staff array with three Employee objects
      Employee[] staff = new Employee[4];

      staff[0] = new Employee("Carl Cracker", 75000, 1987, 12, 15);
      staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
      staff[2] = new Employee(null, 40000, 1990, 3, 15);

      // 如果可以通过变量的初始值推断出它的类型，就可以用 var 关键字声明局部变量，而无需指定类型
      // var 关键字只能用于方法中的局部变量，参数和字段类型必须声明
      var james = new Employee("james", 10000, 1999, 9, 19);
      staff[3] = james;

      // raise everyone's salary by 5%
      for (Employee e : staff)
         e.raiseSalary(5);

      // print out information about all Employee objects
      for (Employee e : staff)
         System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" 
            + e.getHireDay());
   }
}

class Employee
{
   private String name;
   private double salary;
   private LocalDate hireDay;

   /**
   * 构造器总是结合 new 运算符来调用,不能用如下语句
   * Employee james;
   * james.Employee("james", 10000, 1999, 9, 19); // 编译不通过的，这点与C++不同
   */
   public Employee(String n, double s, int year, int month, int day)
   {
      // 表明 name 字段不允许为空，若为空就打印后面的语句并弹出异常 【i109】
      // 如果注释掉该语句，就会打印 name=null,salary=42000.0,hireDay=1990-03-15
      Objects.requireNonNull(n, "The name cannot be null");
      name = n;
      salary = s;
      hireDay = LocalDate.of(year, month, day);
   }

   public String getName()
   {
      return name;
   }

   public double getSalary()
   {
      return salary;
   }

   public LocalDate getHireDay()
   {
      return hireDay;
   }

   /**
    * C++中在类的内部定义方法将默认是内联方法，
    * Java 中，所有方法必须在类的内部定义，但并不代表它们是内联方法。
    * 是否是将某个方法设置为内联方法是 Java 虚拟机的任务。
    */
   public void raiseSalary(double byPercent)
   {
      double raise = salary * byPercent / 100;
      salary += raise;
   }
}
