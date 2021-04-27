
const int out = 18;

// note frequencies: C, C#, D, D#, E, F, F#, G, G#, A, A#, B
const float note[12] = {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47
                       };

const int notesNumber = 32;
const int bpm = 150;

const int song[][3] = { {4, 2, 2}, {5, 2, 1}, {7, 2, 3}, {0, 3, 6}, 
{2, 2, 2}, {4, 2, 1},{5, 2, 8}, 
{7, 2, 2},  {9, 2, 1},  {11, 2, 3},  {5, 3, 6},
{9, 2, 2}, {11, 2, 1}, {0, 3, 3}, {2, 3, 3}, {4, 3, 3},
{4, 2, 2}, {5, 2, 1}, {7, 2, 3}, {0, 3, 6},
{2, 3, 2}, {4, 3, 1},{5, 3, 8}, 
{7, 2, 2}, {7, 2, 1}, {4, 3, 3}, {2, 3, 2},
{7, 2, 1}, {5, 3, 3}, {4, 3, 2}, {2, 3, 1},{0, 3, 8}
};

void setup() {
  ledcAttachPin(out, 0); //broche 18 associée au canal PWM 0
}

void loop() {

  int freq;

  for ( int i = 0; i < notesNumber ; i++ ) {
    freq = round(note[song[i][0]] * 2.0 * (song[i][1] - 1));
    ledcSetup(0, freq, 12);   
    ledcWrite(0, 2048);  // duty cycle 50%
    delay(bpm * song[i][2] - 50);
    ledcWrite(0, 0); // duty cycle 0% to slice notes
  }
delay(2000);
}
