package com.newarchtricks

import android.graphics.Color
import android.view.View
import com.facebook.react.module.annotations.ReactModule
import com.facebook.react.uimanager.ReactStylesDiffMap
import com.facebook.react.uimanager.SimpleViewManager
import com.facebook.react.uimanager.StateWrapper
import com.facebook.react.uimanager.ThemedReactContext
import com.facebook.react.uimanager.annotations.ReactProp
import com.facebook.react.viewmanagers.NewArchTricksViewManagerDelegate
import com.facebook.react.viewmanagers.NewArchTricksViewManagerInterface

@ReactModule(name = NewArchTricksViewManager.NAME)
class NewArchTricksViewManager : SimpleViewManager<NewArchTricksView>(), NewArchTricksViewManagerInterface<NewArchTricksView> {
  private val delegate = NewArchTricksViewManagerDelegate(this)

  override fun getDelegate() = delegate
  override fun getName() = NAME

  override fun createViewInstance(reactContext: ThemedReactContext): NewArchTricksView {
    return NewArchTricksView(reactContext)
  }

  @ReactProp(name = "color")
  override fun setColor(view: NewArchTricksView?, color: String?) {
    view!!.setBackgroundColor(Color.parseColor(color))
  }

  override fun updateState(
    view: NewArchTricksView,
    props: ReactStylesDiffMap?,
    stateWrapper: StateWrapper?
  ): Any? {
    view.setStateWrapper(stateWrapper)

    return super.updateState(view, props, stateWrapper)
  }

  companion object {
    const val NAME = "NewArchTricksView"
  }
}
