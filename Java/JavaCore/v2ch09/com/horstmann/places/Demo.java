package com.horstmann.places;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;

public class Demo {
   public static void main(String[] args) throws JAXBException {
      Country belgium = new Country("Belgium", 30510);
      JAXBContext context = JAXBContext.newInstance(Country.class);
      Marshaller m = context.createMarshaller();
      m.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
      m.marshal(belgium, System.out);
   }
}
