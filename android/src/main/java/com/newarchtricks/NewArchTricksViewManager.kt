package com.newarchtricks

import android.graphics.Color
import android.view.View
import com.facebook.react.module.annotations.ReactModule
import com.facebook.react.uimanager.SimpleViewManager
import com.facebook.react.uimanager.ThemedReactContext
import com.facebook.react.uimanager.annotations.ReactProp
import com.facebook.react.viewmanagers.NewArchTricksViewManagerDelegate
import com.facebook.react.viewmanagers.NewArchTricksViewManagerInterface

@ReactModule(name = NewArchTricksViewManager.NAME)
class NewArchTricksViewManager : SimpleViewManager<View>(), NewArchTricksViewManagerInterface<View> {
  private val delegate = NewArchTricksViewManagerDelegate(this)

  override fun getDelegate() = delegate
  override fun getName() = NAME

  init {
    setupViewRecycling()
  }

  override fun prepareToRecycleView(reactContext: ThemedReactContext, view: View): View? {
    view.setBackgroundColor(Color.BLACK)

    return super.prepareToRecycleView(reactContext, view)
  }

  override fun createViewInstance(reactContext: ThemedReactContext): View {
    return View(reactContext)
  }

  @ReactProp(name = "color")
  override fun setColor(view: View?, color: String?) {
    view!!.setBackgroundColor(Color.parseColor(color))
  }

  companion object {
    const val NAME = "NewArchTricksView"
  }
}
