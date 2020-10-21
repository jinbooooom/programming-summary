package spinner;

import java.awt.*;
import java.awt.event.*;
import java.text.*;
import javax.swing.*;

/**
 * A frame with a panel that contains several spinners and a button that displays the spinner
 * values.
 */
public class SpinnerFrame extends JFrame
{
   private JPanel mainPanel;
   private JButton okButton;

   public SpinnerFrame()
   {
      var buttonPanel = new JPanel();
      okButton = new JButton("Ok");
      buttonPanel.add(okButton);
      add(buttonPanel, BorderLayout.SOUTH);

      mainPanel = new JPanel();
      mainPanel.setLayout(new GridLayout(0, 3));
      add(mainPanel, BorderLayout.CENTER);

      var defaultSpinner = new JSpinner();
      addRow("Default", defaultSpinner);

      var boundedSpinner = new JSpinner(new SpinnerNumberModel(5, 0, 10, 0.5));
      addRow("Bounded", boundedSpinner);

      String[] fonts = GraphicsEnvironment.getLocalGraphicsEnvironment()
            .getAvailableFontFamilyNames();

      JSpinner listSpinner = new JSpinner(new SpinnerListModel(fonts));
      addRow("List", listSpinner);

      var reverseListSpinner = new JSpinner(new SpinnerListModel(fonts)
         {
            public Object getNextValue() { return super.getPreviousValue(); }
            public Object getPreviousValue() { return super.getNextValue(); }
         });
      addRow("Reverse List", reverseListSpinner);

      var dateSpinner = new JSpinner(new SpinnerDateModel());
      addRow("Date", dateSpinner);

      var betterDateSpinner = new JSpinner(new SpinnerDateModel());
      String pattern = ((SimpleDateFormat) DateFormat.getDateInstance()).toPattern();
      betterDateSpinner.setEditor(new JSpinner.DateEditor(betterDateSpinner, pattern));
      addRow("Better Date", betterDateSpinner);
      
      var timeSpinner = new JSpinner(new SpinnerDateModel());
      pattern = ((SimpleDateFormat) DateFormat.getTimeInstance(DateFormat.SHORT)).toPattern();
      timeSpinner.setEditor(new JSpinner.DateEditor(timeSpinner, pattern));
      addRow("Time", timeSpinner);

      var permSpinner = new JSpinner(new PermutationSpinnerModel("meat"));
      addRow("Word permutations", permSpinner);
      pack();
   }

   /**
    * Adds a row to the main panel.
    * @param labelText the label of the spinner
    * @param spinner the sample spinner
    */
   public void addRow(String labelText, final JSpinner spinner)
   {
      mainPanel.add(new JLabel(labelText));
      mainPanel.add(spinner);
      var valueLabel = new JLabel();
      mainPanel.add(valueLabel);
      okButton.addActionListener(event ->
         {
            Object value = spinner.getValue();
            valueLabel.setText(value.toString());
         });
   }
}
