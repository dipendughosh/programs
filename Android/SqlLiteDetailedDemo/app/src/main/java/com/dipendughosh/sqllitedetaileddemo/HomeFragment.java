package com.dipendughosh.sqllitedetaileddemo;


import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;


/**
 * A simple {@link Fragment} subclass.
 */
public class HomeFragment extends Fragment implements View.OnClickListener{

    private Button BnAdd;
    private Button BnView;
    private Button BnDelete;
    private Button BnUpdate;

    OnDbOpListner dbOpListner;

    public HomeFragment() {
        // Required empty public constructor
    }
    public interface OnDbOpListner {

        public void dbOpPerformed(int method);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);
        BnAdd = view.findViewById(R.id.bn_add_contact);
        BnAdd.setOnClickListener(this);
        BnView = view.findViewById(R.id.bn_view_contact);
        BnView.setOnClickListener(this);
        BnUpdate = view.findViewById(R.id.bn_update_contact);
        BnUpdate.setOnClickListener(this);
        BnDelete = view.findViewById(R.id.bn_delete_contact);
        BnDelete.setOnClickListener(this);
        // Inflate the layout for this fragment
        return view;
    }

    @Override
    public void onClick(View v) {
        switch(v.getId()) {
            case R.id.bn_add_contact:
                dbOpListner.dbOpPerformed(0);
                break;
            case R.id.bn_view_contact:
                dbOpListner.dbOpPerformed(1);
                break;
            case R.id.bn_update_contact:
                dbOpListner.dbOpPerformed(2);
                break;
            case R.id.bn_delete_contact:
                dbOpListner.dbOpPerformed(3);
                break;
        }
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        Activity activity = (Activity) context;
        try {
            dbOpListner = (OnDbOpListner) activity;
        }
        catch (ClassCastException e) {
            throw new ClassCastException(activity.toString() + "must override OnMessageReadListner");
        }

    }
}
