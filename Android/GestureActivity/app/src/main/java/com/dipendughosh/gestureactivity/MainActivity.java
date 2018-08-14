package com.dipendughosh.gestureactivity;

import android.support.v4.view.GestureDetectorCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import android.view.MotionEvent;
import android.gesture.Gesture;
import android.view.GestureDetector;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements GestureDetector.OnGestureListener, GestureDetector.OnDoubleTapListener {

    private static TextView textView;

    private GestureDetectorCompat GestureDetect;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = (TextView) findViewById(R.id.textView);
        GestureDetect = new GestureDetectorCompat(this, this);
        GestureDetect.setOnDoubleTapListener(this);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        GestureDetect.onTouchEvent(event);
        return super.onTouchEvent(event);
    }

    @Override
    public boolean onSingleTapConfirmed(MotionEvent e) {
        textView.setText("onSingleTapConfirmed" + " " + e.toString());
        Toast.makeText(this, "onSingleTapConfirmed", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public boolean onDoubleTap(MotionEvent e) {
        textView.setText("onDoubleTap" + " " + e.toString());
        Toast.makeText(this, "onDoubleTap", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public boolean onDoubleTapEvent(MotionEvent e) {
        textView.setText("onDoubleTapEvent" + " " + e.toString());
        Toast.makeText(this, "onDoubleTapEvent", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public boolean onDown(MotionEvent e) {
        textView.setText("onDown" + " " + e.toString());
        Toast.makeText(this, "onDown", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public void onShowPress(MotionEvent e) {
        textView.setText("onShowPress" + " " + e.toString());
        Toast.makeText(this, "onShowPress", Toast.LENGTH_SHORT).show();
    }

    @Override
    public boolean onSingleTapUp(MotionEvent e) {
        textView.setText("onSingleTapUp" + " " + e.toString());
        Toast.makeText(this, "onSingleTapUp", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY) {
        textView.setText("onScroll" + " " + e1.toString() + " " + e2.toString());
        Toast.makeText(this, "onScroll", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public void onLongPress(MotionEvent e) {
        textView.setText("onLongPress" + " " + e.toString());
        Toast.makeText(this, "onLongPress", Toast.LENGTH_SHORT).show();
    }

    @Override
    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
        textView.setText("onFling" + " " + e1.toString() + " " + e2.toString());
        Toast.makeText(this, "onFling", Toast.LENGTH_SHORT).show();
        return false;
    }

    @Override
    public void onPointerCaptureChanged(boolean hasCapture) {
        textView.setText("onPointerCaptureChanged");
        Toast.makeText(this, "onPointerCaptureChanged", Toast.LENGTH_SHORT).show();
    }
}
