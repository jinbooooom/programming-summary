package longList;

import java.awt.*;
import javax.swing.*;

/**
 * This program demonstrates a list that dynamically computes list entries.
 * @version 1.25 2018-05-01
 * @author Cay Horstmann
 */
public class LongListTest
{
   public static void main(String[] args)
   {
      EventQueue.invokeLater(() ->
         {
            var frame = new LongListFrame();
            frame.setTitle("LongListTest");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
         });
   }
}


