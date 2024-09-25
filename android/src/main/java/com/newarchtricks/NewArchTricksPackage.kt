package com.newarchtricks

import com.facebook.react.TurboReactPackage
import com.facebook.react.bridge.NativeModule
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.module.model.ReactModuleInfo
import com.facebook.react.module.model.ReactModuleInfoProvider
import com.facebook.react.uimanager.ViewManager


class NewArchTricksPackage : TurboReactPackage() {
  override fun createViewManagers(reactContext: ReactApplicationContext): List<ViewManager<*, *>> {
    return listOf(NewArchTricksViewManager())
  }

   override fun getModule(name: String, reactContext: ReactApplicationContext): NativeModule? =
     if (name == NewArchTricksModule.NAME) {
       NewArchTricksModule(reactContext)
     } else {
       null
     }

   override fun getReactModuleInfoProvider() = ReactModuleInfoProvider {
     mapOf(
       NewArchTricksModule.NAME to ReactModuleInfo(
         NewArchTricksModule.NAME,
         NewArchTricksModule.NAME,
         false, // canOverrideExistingModule
         false, // needsEagerInit
         false, // isCxxModule
         true // isTurboModule
       )
     )
   }
}
