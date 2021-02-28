import java.util.*;

/**
 * This program demonstrates enumerated types.
 * @version 1.0 2004-05-24
 * @author Cay Horstmann
 */
public class EnumTest
{  
   public static void main(String[] args)
   {  
      var in = new Scanner(System.in);
      System.out.print("Enter a size: (SMALL, MEDIUM, LARGE, EXTRA_LARGE) ");
      String input = in.next().toUpperCase();
      // 假设 input 输入的是 SMALL， 
      // 则将枚举变量 size 的值设置为 Size.SMALL，即 S
      Size size = Enum.valueOf(Size.class, input);
      System.out.println("size=" + size);
      System.out.println("abbreviation=" + size.getAbbreviation());
      if (size == Size.EXTRA_LARGE)
         System.out.println("Good job--you paid attention to the _.");      
   }
}

// 所有的枚举类都是 Enum 的子类
enum Size
{
   // S 才是属性， SMALL 是外面调用时用的
   SMALL("S"), MEDIUM("M"), LARGE("L"), EXTRA_LARGE("XL");

   private Size(String abbreviation) { this.abbreviation = abbreviation; }
   public String getAbbreviation() { return abbreviation; }

   private String abbreviation;
}
