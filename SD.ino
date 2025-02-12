void init_sdcard() {
  // setup for the SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  if (SD.exists("EXAMPLE.txt")) {
    Serial.println("EXAMPLE.txt exists.");
  } else {
    Serial.println("EXAMPLE.txt doesn't exist.");
    // open a new file and immediately close it:
    Serial.println("Creating EXAMPLE.txt...");
    myFile = SD.open("EXAMPLE.txt", FILE_WRITE);
    myFile.println("writing...");
    myFile.close();
  }

}
