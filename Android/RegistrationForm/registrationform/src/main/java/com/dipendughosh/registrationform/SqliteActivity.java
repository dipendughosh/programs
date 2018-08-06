package com.dipendughosh.registrationform;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import java.sql.SQLData;

public class SqliteActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sqlite);

        StudentDbHelper dbHelper=new StudentDbHelper(this);
        /*SQLiteDatabase db=dbHelper.getWritableDatabase();

        ContentValues values=new ContentValues();
        values.put("sid","2");
        values.put("sname","Moumita");
        values.put("marks",40);

        long row=db.insert("student",null,values);

        System.out.println("row number is : "+row);*/

        SQLiteDatabase db=dbHelper.getReadableDatabase();

        String projection[]={"sid", "sname", "marks"};

        Cursor c=db.query("student",projection,null,null,null,null,null);

        c.moveToPosition(1);

        System.out.println("name is "+c.getString(1));
    }
}
