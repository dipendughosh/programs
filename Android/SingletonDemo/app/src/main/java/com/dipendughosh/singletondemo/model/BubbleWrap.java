package com.dipendughosh.singletondemo.model;

public class BubbleWrap {
    private static final int ADD_MORE_BUBBLES = 10;
    private int numBubbles;

    /*
    Singleton Support
     */
    private static  BubbleWrap instance;
    private BubbleWrap() {

    }
    public static BubbleWrap getInstance() {
        if (instance == null) {
            instance = new BubbleWrap();
        }
        return instance;
    }

    public int getNumBubbles() {
        return numBubbles;
    }

    public void addMoreBubbles() {
        numBubbles += ADD_MORE_BUBBLES;
    }

    public void popBubble() {
        numBubbles--;
    }
}
