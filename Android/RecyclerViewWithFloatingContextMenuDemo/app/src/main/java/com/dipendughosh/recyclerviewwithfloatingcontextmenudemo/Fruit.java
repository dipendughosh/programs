package com.dipendughosh.recyclerviewwithfloatingcontextmenudemo;

public class Fruit {

    private int fruit_imaage_id;
    private String fruit_name;

    public Fruit(int fruit_imaage_id, String fruit_name) {
        this.fruit_imaage_id = fruit_imaage_id;
        this.fruit_name = fruit_name;
    }

    public int getFruit_imaage_id() {
        return fruit_imaage_id;
    }

    public void setFruit_imaage_id(int fruit_imaage_id) {
        this.fruit_imaage_id = fruit_imaage_id;
    }

    public String getFruit_name() {
        return fruit_name;
    }

    public void setFruit_name(String fruit_name) {
        this.fruit_name = fruit_name;
    }
}
