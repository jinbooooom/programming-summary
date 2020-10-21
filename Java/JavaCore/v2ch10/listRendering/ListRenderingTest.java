package listRendering;

import java.awt.*;
import javax.swing.*;

/**
 * This program demonstrates the use of cell renderers in a list box.
 * @version 1.26 2018-05-01
 * @author Cay Horstmann
 */
public class ListRenderingTest
{
   public static void main(String[] args)
   {
      EventQueue.invokeLater(() ->
         {
            var frame = new ListRenderingFrame();
            frame.setTitle("ListRenderingTest");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
         });
   }
}
