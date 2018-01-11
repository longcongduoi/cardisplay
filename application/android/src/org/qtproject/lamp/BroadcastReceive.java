package org.qtproject.lamp;

/**
 * Created by tamvh on 08/10/2016.
 */

import android.annotation.TargetApi;
import android.app.Service;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.bluetooth.le.AdvertiseCallback;
import android.bluetooth.le.AdvertiseData;
import android.bluetooth.le.AdvertiseSettings;
import android.bluetooth.le.BluetoothLeAdvertiser;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Handler;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;
import android.app.Notification;
import android.app.NotificationManager;

import java.io.Console;
import java.lang.reflect.Array;
import java.util.concurrent.TimeUnit;


public class BroadcastReceive{

}
