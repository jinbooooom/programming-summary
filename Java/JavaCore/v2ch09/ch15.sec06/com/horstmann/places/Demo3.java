package com.horstmann.places;

import com.horstmann.util.*;
   
public class Demo3 {
   public static void main(String[] args) throws ReflectiveOperationException {
      Country belgium = new Country("Belgium", 30510);
      ObjectAnalyzer analyzer = new ObjectAnalyzer();
      System.out.println(analyzer.toString(belgium));
   }
}
