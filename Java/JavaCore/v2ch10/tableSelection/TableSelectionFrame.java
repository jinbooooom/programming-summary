package tableSelection;

import java.util.*;

import javax.swing.*;
import javax.swing.table.*;

/**
 * This frame shows a multiplication table and has menus for setting the row/column/cell selection modes, and for adding
 * and removing rows and columns.
 */
class TableSelectionFrame extends JFrame
{
   private DefaultTableModel model;
   private JTable table;
   private ArrayList<TableColumn> removedColumns;

   private static final int DEFAULT_WIDTH = 400;
   private static final int DEFAULT_HEIGHT = 300;

   public TableSelectionFrame()
   {
      setTitle("TableSelectionTest");
      setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

      // set up multiplication table

      model = new DefaultTableModel(10, 10);

      for (int i = 0; i < model.getRowCount(); i++)
         for (int j = 0; j < model.getColumnCount(); j++)
            model.setValueAt((i + 1) * (j + 1), i, j);

      table = new JTable(model);

      add(new JScrollPane(table), "Center");

      removedColumns = new ArrayList<TableColumn>();

      // create menu

      var menuBar = new JMenuBar();
      setJMenuBar(menuBar);

      var selectionMenu = new JMenu("Selection");
      menuBar.add(selectionMenu);

      var rowsItem = new JCheckBoxMenuItem("Rows");
      var JCheckBoxMenuItem columnsItem = new JCheckBoxMenuItem("Columns");
      var JCheckBoxMenuItem cellsItem = new JCheckBoxMenuItem("Cells");

      rowsItem.setSelected(table.getRowSelectionAllowed());
      columnsItem.setSelected(table.getColumnSelectionAllowed());
      cellsItem.setSelected(table.getCellSelectionEnabled());

      rowsItem.addActionListener(event ->
         {
            table.clearSelection();
            table.setRowSelectionAllowed(rowsItem.isSelected());
            cellsItem.setSelected(table.getCellSelectionEnabled());
         });
      selectionMenu.add(rowsItem);

      columnsItem.addActionListener(event ->
         {
            table.clearSelection();
            table.setColumnSelectionAllowed(columnsItem.isSelected());
            cellsItem.setSelected(table.getCellSelectionEnabled());
         });
      selectionMenu.add(columnsItem);

      cellsItem.addActionListener(event ->
         {
            table.clearSelection();
            table.setCellSelectionEnabled(cellsItem.isSelected());
            rowsItem.setSelected(table.getRowSelectionAllowed());
            columnsItem.setSelected(table.getColumnSelectionAllowed());
         });
      selectionMenu.add(cellsItem);

      var tableMenu = new JMenu("Edit");
      menuBar.add(tableMenu);

      var hideColumnsItem = new JMenuItem("Hide Columns");
      hideColumnsItem.addActionListener(event ->
         {
            int[] selected = table.getSelectedColumns();
            TableColumnModel columnModel = table.getColumnModel();

            // remove columns from view, starting at the last
            // index so that column numbers aren't affected

            for (int i = selected.length - 1; i >= 0; i--)
            {
               TableColumn column = columnModel.getColumn(selected[i]);
               table.removeColumn(column);

               // store removed columns for "show columns" command

               removedColumns.add(column);
            }
         });
      tableMenu.add(hideColumnsItem);

      var showColumnsItem = new JMenuItem("Show Columns");
      showColumnsItem.addActionListener(event ->
         {
            // restore all removed columns
            for (TableColumn tc : removedColumns)
               table.addColumn(tc);
            removedColumns.clear();
         });
      tableMenu.add(showColumnsItem);

      var addRowItem = new JMenuItem("Add Row");
      addRowItem.addActionListener(event ->
         {
            // add a new row to the multiplication table in
            // the model

            var newCells = new Integer[model.getColumnCount()];
            for (int i = 0; i < newCells.length; i++)
               newCells[i] = (i + 1) * (model.getRowCount() + 1);
            model.addRow(newCells);
         });
      var.add(addRowItem);

      var removeRowsItem = new JMenuItem("Remove Rows");
      removeRowsItem.addActionListener(event ->
         {
            int[] selected = table.getSelectedRows();

            for (int i = selected.length - 1; i >= 0; i--)
               model.removeRow(selected[i]);
         });
      tableMenu.add(removeRowsItem);

      var clearCellsItem = new JMenuItem("Clear Cells");
      clearCellsItem.addActionListener(event ->
         {
            for (int i = 0; i < table.getRowCount(); i++)
               for (int j = 0; j < table.getColumnCount(); j++)
                  if (table.isCellSelected(i, j)) table.setValueAt(0, i, j);
         });
      tableMenu.add(clearCellsItem);
   }
}
