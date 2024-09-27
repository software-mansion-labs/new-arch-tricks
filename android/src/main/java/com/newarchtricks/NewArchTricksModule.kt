package com.newarchtricks

import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.fabric.FabricUIManager
import com.facebook.react.module.annotations.ReactModule
import com.facebook.react.turbomodule.core.interfaces.BindingsInstallerHolder
import com.facebook.react.turbomodule.core.interfaces.TurboModuleWithJSIBindings
import com.facebook.react.uimanager.UIManagerHelper
import com.facebook.react.uimanager.common.UIManagerType


@ReactModule(name = NewArchTricksModule.NAME)
class NewArchTricksModule(reactContext: ReactApplicationContext) : NativeNewArchTricksModuleSpec(reactContext), TurboModuleWithJSIBindings {
  @DoNotStrip
  @Suppress("unused")
  private var mHybridData: HybridData = initHybrid()

  private external fun initHybrid(): HybridData
  private external fun createCommitHook(fabricUIManager: FabricUIManager)
  private external fun getBindingsInstallerCxx(): BindingsInstallerHolder

  override fun getName() = NAME

  override fun multiply(a: Double, b: Double): Double {
    return a * b
  }

  override fun install() {
    val uiManager =
      UIManagerHelper.getUIManager(
        reactApplicationContext,
        UIManagerType.FABRIC
      ) as FabricUIManager

    createCommitHook(uiManager)
  }

  companion object {
    const val NAME = "NewArchTricks"
  }

  override fun getBindingsInstaller() = getBindingsInstallerCxx()
}
