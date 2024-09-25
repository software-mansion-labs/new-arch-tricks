import { StyleSheet, View, Pressable } from 'react-native';
import { NewArchTricksView, multiply } from 'react-native-new-arch-tricks';

export default function App() {
  return (
    <View style={styles.container}>
      <Pressable onPress={() => console.log(multiply(3, 7))}>
        <NewArchTricksView color="#32a852" style={styles.box} />
      </Pressable>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
