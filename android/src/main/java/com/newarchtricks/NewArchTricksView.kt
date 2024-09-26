package com.newarchtricks

import android.app.Activity
import android.content.Context
import android.os.Build
import android.view.View
import android.view.WindowInsets
import androidx.annotation.RequiresApi
import com.facebook.react.bridge.Arguments
import com.facebook.react.bridge.ReactContext
import com.facebook.react.uimanager.PixelUtil
import com.facebook.react.uimanager.StateWrapper

class NewArchTricksView(context: Context): View(context) {
  private var stateWrapper: StateWrapper? = null

  fun setStateWrapper(stateWrapper: StateWrapper?) {
    this.stateWrapper = stateWrapper
  }

  @RequiresApi(Build.VERSION_CODES.R)
  override fun onAttachedToWindow() {
    super.onAttachedToWindow()

    val decorView = (context as ReactContext).currentActivity!!.window.decorView
    val height = decorView.rootWindowInsets.getInsets(WindowInsets.Type.statusBars()).top

    stateWrapper?.updateState(Arguments.createMap().apply {
      putDouble("statusBarWidth", decorView.width.toDouble())
      putDouble("statusBarHeight", PixelUtil.toDIPFromPixel(height.toFloat()).toDouble())
    })
  }
}
