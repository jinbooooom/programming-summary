package com.horstmann.places;

import javax.json.bind.annotation.*;
//import javax.xml.bind.annotation.XmlElement;
//import javax.xml.bind.annotation.XmlRootElement;

//@XmlRootElement
public class Country {
   //@XmlElement
   @JsonbProperty
   private String name;
   //@XmlElement
   private double area;
   private double bogus;

   public Country() {}
   
   public Country(String name, double area) {
      this.name = name;
      this.area = area;
   }
   public String toString()
   {
      return "name=" + name + ",area=" + area;
   }
   /*
   public String getName() {
      return name;
   }

   public double getArea() {
      return area;
   }
   */
}
