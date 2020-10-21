package tabbedPane;

import java.awt.*;
import javax.swing.*;

/**
 * This program demonstrates the tabbed pane component organizer.
 * @version 1.05 2018-05-01
 * @author Cay Horstmann
 */
public class TabbedPaneTest
{
   public static void main(String[] args)
   {
      EventQueue.invokeLater(() ->
         {
            var frame = new TabbedPaneFrame();
            frame.setTitle("TabbedPaneTest");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
         });
   }
}

