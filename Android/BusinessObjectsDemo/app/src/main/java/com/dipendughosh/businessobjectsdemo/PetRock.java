package com.dipendughosh.businessobjectsdemo;

public class PetRock {

    public enum Emotion {TIRED, HAPPY, SAD};
    private Emotion currentEmotion = Emotion.TIRED;

    public Emotion getCurrentEmotion() {
        return currentEmotion;
    }

    public void setCurrentEmotion(Emotion currentEmotion) {
        this.currentEmotion = currentEmotion;
    }

    @Override
    public String toString() {
        return "I'm feeling " + currentEmotion.toString() + ".";
    }
}
