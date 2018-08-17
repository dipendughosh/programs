package com.dipendughosh.roomdemo;

import android.arch.persistence.room.Database;
import android.arch.persistence.room.RoomDatabase;

@Database(entities = {User.class}, version = 1)
public abstract class MyaAppDatabase extends RoomDatabase {

    public abstract MyDao myDao();
}
