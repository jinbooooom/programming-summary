package localInnerClass;

import java.awt.*;
import java.awt.event.*;
import java.time.*;

import javax.swing.*;

/**
 * This program demonstrates the use of local inner classes.
 * @version 1.02 2017-12-14
 * @author Cay Horstmann
 */
public class LocalInnerClassTest
{
   public static void main(String[] args)
   {
      var clock = new TalkingClock();
      clock.start(1000, true);

      // keep program running until the user selects "Ok"
      JOptionPane.showMessageDialog(null, "Quit program?");
      System.exit(0);
   }
}

/**
 * A clock that prints the time in regular intervals.
 */
class TalkingClock
{
   /**
    * Starts the clock.
    * @param interval the interval between messages (in milliseconds)
    * @param beep true if the clock should beep
    */
   public void start(int interval, boolean beep)
   {
      // 【i263】
      // 声明局部类时是不能有访问说明符的，局部类的作用域被限制在声明这个局部类的块中
      // 局部类对外部世界完全隐藏但它可以访问外部类的字段（必须是事实最终变量），如下面的变量 beep。
      class TimePrinter implements ActionListener
      {
         public void actionPerformed(ActionEvent event)
         {
            System.out.println("At the tone, the time is " 
                  + Instant.ofEpochMilli(event.getWhen()));
            if (beep) Toolkit.getDefaultToolkit().beep();
         }
      }
      var listener = new TimePrinter();
      var timer = new Timer(interval, listener);
      timer.start();
   }
}
