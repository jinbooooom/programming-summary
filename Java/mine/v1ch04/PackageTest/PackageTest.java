import com.horstmann.corejava.*;
// the Employee class is defined in that package

import static java.lang.System.*;

/**
 * This program demonstrates the use of packages.
 * @version 1.11 2004-02-19
 * @author Cay Horstmann
 */

/**
 * Java 允许使用包将类组织在一个集合中，借助包可以方便地组织自己的代码，
 * 并将自己的代码与别人的代码库区分开。
 * 从编译器的角度看，嵌套的包之间没有任何关系。每一个包都是独立的类集合。
 * 
 * 在C++中，与包机制类似的是命名空间而不是 #include。
 * package 类似 namespace
 * import 类似 using
 * 
 * 包访问：
 * 类内标记为 public 的部分可以由任意类使用，标记为 private的类只能由定义它们的类使用。
 * 而没有指定 public 和 private 的，默认为 public。
 * 
 * jar 包：
 * 【i143】
 */
public class PackageTest
{
   public static void main(String[] args)
   {
      // because of the import statement, we don't have to use 
      // com.horstmann.corejava.Employee here
      var harry = new Employee("Harry Hacker", 50000, 1989, 10, 1);

      harry.raiseSalary(5);

      // because of the static import statement, we don't have to use System.out here
      out.println("name=" + harry.getName() + ",salary=" + harry.getSalary());
   }
}
