import NativeNewArchTricksModule from './specs/NativeNewArchTricksModule';

export function multiply(a: number, b: number): number {
  return NativeNewArchTricksModule.multiply(a, b);
}

export function install(): void {
  NativeNewArchTricksModule.install();
}
