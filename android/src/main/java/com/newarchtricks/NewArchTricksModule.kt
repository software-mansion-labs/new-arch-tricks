package com.newarchtricks

import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.annotations.ReactModule

@ReactModule(name = NewArchTricksModule.NAME)
class NewArchTricksModule(reactContext: ReactApplicationContext) : NativeNewArchTricksModuleSpec(reactContext) {
  override fun getName() = NAME

  override fun multiply(a: Double, b: Double): Double {
    return a * b
  }

  companion object {
    const val NAME = "NewArchTricks"
  }
}
