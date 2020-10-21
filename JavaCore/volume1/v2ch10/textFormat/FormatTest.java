package textFormat;

import java.awt.*;
import javax.swing.*;

/**
 * A program to test formatted text fields
 * @version 1.05 2018-05-01
 * @author Cay Horstmann
 */
public class FormatTest
{
   public static void main(String[] args)
   {
      EventQueue.invokeLater(() ->
         {
            var frame = new FormatTestFrame();
            frame.setTitle("FormatTest");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
         });
   }
}

