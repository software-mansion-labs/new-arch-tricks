import React from 'react';
import NewArchTricksNativeComponent from './specs/NewArchTricksNativeComponent';
import type { NativeProps } from './specs/NewArchTricksNativeComponent';
// @ts-ignore this is not exposed
import ReactNativeInterface from 'react-native/Libraries/ReactPrivate/ReactNativePrivateInterface';

export const NewArchTricksView = React.forwardRef<any, NativeProps>(
  (props, forwardedRef) => {
    const localRef = React.useRef<any>(null);
    const [_registered, setRegistered] = React.useState(false);

    return (
      <NewArchTricksNativeComponent
        {...props}
        ref={(ref) => {
          if (ref) {
            const node = ReactNativeInterface.getNodeFromPublicInstance(ref);
            // @ts-ignore injected via JSI
            global.__NAT_registerNode(node);

            localRef.current = ref;
            setRegistered(true);
          } else {
            const node = ReactNativeInterface.getNodeFromPublicInstance(
              localRef.current
            );
            // @ts-ignore injected via JSI
            global.__NAT_unregisterNode(node);
            localRef.current = null;
          }

          if (forwardedRef) {
            if (typeof forwardedRef === 'function') {
              forwardedRef(ref);
            } else {
              (forwardedRef as React.MutableRefObject<any>).current = ref;
            }
          }
        }}
      />
    );
  }
);
