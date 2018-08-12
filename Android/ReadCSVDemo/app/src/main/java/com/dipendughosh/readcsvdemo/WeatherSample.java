package com.dipendughosh.readcsvdemo;

class WeatherSample {

    private String month;
    private double rain;
    private double sun;

    public String getMonth() {
        return month;
    }

    public void setMonth(String month) {
        this.month = month;
    }

    public double getRain() {
        return rain;
    }

    public void setRain(double rain) {
        this.rain = rain;
    }

    public double getSun() {
        return sun;
    }

    public void setSun(double sun) {
        this.sun = sun;
    }

    @Override
    public String toString() {
        return "WeatherSample{" +
                "month='" + month + '\'' +
                ", rain=" + rain +
                ", sun=" + sun +
                '}';
    }
}
