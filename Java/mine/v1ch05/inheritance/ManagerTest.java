
//package inheritance;
// 上面语句不可以运行。说明包名是当前目录下的文件夹

import jinbo.*;

/**
 * This program demonstrates inheritance.
 * @version 1.21 2004-02-21
 * @author Cay Horstmann
 */
public class ManagerTest
{
   public static void main(String[] args)
   {
      // construct a Manager object
      var boss = new Manager("Carl Cracker", 80000, 1987, 12, 15);
      boss.setBonus(5000);

      var staff = new Employee[3];

      // fill the staff array with Manager and Employee objects

      staff[0] = boss;
      // staff[0] 是 Manager 类实例boss的引用，但是它不能调用setBonus()方法
      // staff[0].setBonus(6666); // 编译错误
      staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
      staff[2] = new Employee("Tommy Tester", 40000, 1990, 3, 15);

      // print out information about all Employee objects
      for (Employee e : staff)
         System.out.println("name=" + e.getName() + ",salary=" + e.getSalary());
   }
}
