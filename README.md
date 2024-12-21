# Audio Processing Project

This project is an audio processing tool that allows manipulation of audio files using various strategies. The core functionality revolves around applying different audio effects like changing speed, volume, reverb, and reversing audio. The strategies are designed to be modular, enabling the user to extend the system by adding new audio effects.

## Related Project

Based on this console-based application, I made an enhanced version of Win32 desktop application. You can check it out [here](https://github.com/amWRit/AudioProcessorWin32APP).

---

## **Class Details**

### **AudioFileHandler (Abstract Base Class)**

-   **Methods:**
    -   `loadAudio(const std::string& filePath) : bool` (pure virtual)
    -   `saveAudio(const std::string& filePath, const std::vector<double>& timeDomainSignal, double sampleRate) : void` (pure virtual)
    -   `getBuffer() : const std::vector<std::vector<double>>&`  (pure virtual)
    -   `getSampleRate() : int`  (pure virtual)
    -   `getBitDepth() : int`  (pure virtual)

---

### **AudioFileHandlerFactory**

-   **Methods:**
    -   `createAudioFileHandler(const std::string& type) : std::shared_ptr<AudioFileHandler>` (static)

---

### **WaveAudioFileHandler (Derived from AudioFileHandler)**

-   **Methods:**
    -   `loadAudio(const std::string& filePath) : bool` (overrides)
    -   `saveAudio(const std::string& filePath, const std::vector<double>& timeDomainSignal, double sampleRate) : void` (overrides)
    -   `getBuffer() : const std::vector<std::vector<double>>&`  (overrides)
    -   `getSampleRate() : int`  (overrides)
    -   `getBitDepth() : int` (overrides)

---

### **AudioProcessingStrategy (Abstract Base Class)**

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (pure virtual)

---

### **AudioProcessingStrategyFactory**
The `AudioProcessingStrategyFactory` class is responsible for creating instances of different audio processing strategies based on the strategy type provided. The factory supports various strategies such as audio extraction, speed change, volume change, reverb, and audio reversal. It can also create strategies for specific instruments when an instrument type is provided.
-   **Methods:**
    -   `static std::shared_ptr<AudioProcessingStrategy> createStrategy(const std::string& strategyType, const std::string& instrumentType = "", double factor = 1.0)`
  
    - **Parameters:**
        - `strategyType`: A string that determines the type of audio processing strategy to create. Example values include `"audioExtract"`, `"changeAudioSpeed"`, `"changeAudioVolume"`, `"audioReverb"`, and `"audioReverse"`.
        - `instrumentType`: (Optional) A string specifying the type of instrument when the strategy involves frequency extraction. Examples might include `"guitar"`, `"bass"`, etc.
        - `factor`: (Optional) A numeric value used for strategies that require a factor (e.g., speed or volume). Default value is 1.0.

    - **Example:**
        ```cpp
        std::shared_ptr<AudioProcessingStrategy> strategy = AudioProcessingStrategyFactory::createStrategy("changeAudioSpeed", "", 1.5);
        ```

    - **Strategy Examples:**
        - **`"audioExtract"`**: Creates an instance of `ExtractAudioChunksStrategy` with frequency parameters based on the given instrument type.
        - **`"changeAudioSpeed"`**: Creates an instance of `ChangeAudioSpeedStrategy` with the given factor.
        - **`"changeAudioVolume"`**: Creates an instance of `ChangeAudioVolumeStrategy` with the given factor.
        - **`"audioReverb"`**: Creates an instance of `AudioReverbStrategy` with reverb intensity and delay time.
        - **`"audioReverse"`**: Creates an instance of `AudioReverseStrategy`.

---

### **ChangeAudioVolumeStrategy (Derived from AudioProcessingStrategy)**

-   **Attributes:**
    -   `double volumeFactor`

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (overrides)

---

### **ReverbStrategy (Derived from AudioProcessingStrategy)**

-   **Attributes:**
    -   `double delayInMilliseconds`
    -   `double reverbIntensity`

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (overrides)

---

### **ReverseAudioStrategy (Derived from AudioProcessingStrategy)**

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (overrides)

---

### **SpeedChangeStrategy (Derived from AudioProcessingStrategy)**

-   **Attributes:**
    -   `double speedFactor`

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (overrides)

---

### **ExtractAudioChunksStrategy (Derived from AudioProcessingStrategy)**
  The `ExtractAudioChunksStrategy` class is designed to extract audio chunks based on a specified frequency range. The strategy processes the audio file by filtering its frequency components and returning the time-domain signal within the given frequency range. This is useful for tasks like isolating specific frequency bands or instruments in an audio file.
-   **Attributes:**
    -   `double minFreq`
    -   `double maxFreq`

-   **Methods:**
    -   `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>` (overrides)

    - **Constructor:**
        - `ExtractAudioChunksStrategy(double minFreq, double maxFreq)`: Initializes the strategy with a minimum and maximum frequency to define the range for extracting audio chunks.

    - **Process Method:**
        - `process(std::shared_ptr<AudioFileHandler> fileHandler) : std::vector<double>`: This method processes the audio file, extracting the frequency components within the specified range (`minFreq` to `maxFreq`), and returns the time-domain signal.

    - **Example:**
        ```cpp
        std::shared_ptr<AudioProcessingStrategy> strategy = AudioProcessingStrategyFactory::createStrategy("audioExtract", "guitar");
        auto extractedSignal = strategy->process(fileHandler);
        ```

---

### **FFTProcessor**

-   **Attributes:**
    -   `size_t fftSize`
    -   `double sampleRate`
    -   `kiss_fft_cfg cfg`
    -   `kiss_fft_cfg cfgInverse`
    -   `std::vector<kiss_fft_cpx> in`
    -   `std::vector<kiss_fft_cpx> out`
  
-   **Methods:**
    -   `performFFT(const std::vector<double>& channelData) : void`
    -   `performIFFT(const std::vector<kiss_fft_cpx>& fftOutput) : std::vector<double>`
    -   `getFFTOutput() : const std::vector<kiss_fft_cpx>&`

---

### **SignalProcessor**

-   **Methods (Static):**
    -   `filterFrequencyComponents(const std::vector<kiss_fft_cpx>& fftOutput, const std::vector<double>& frequencies, double lowFreq, double highFreq) : std::vector<kiss_fft_cpx>`
    -   `compareSignals(const std::vector<double>& original, const std::vector<double>& processed, double tolerance = 1e-6) : bool`
    -   `calculateFrequencies(size_t fftSize, double sampleRate, const std::vector<kiss_fft_cpx>& fftOutput) : std::vector<double>`
    -   `calculateMagnitudes(size_t fftSize, const std::vector<kiss_fft_cpx>& fftOutput) : std::vector<double>`
    -   `extract(const std::vector<double>& channelData, FFTProcessor& fftProcessor, double lowFreq, double highFreq) : std::vector<double>`

---

### **Settings**

-   **Attributes:**
    -   `static size_t fftSize`
  
-   **Methods:**
    -   `static int getFFTSize() : int`
    -   `static void setFFTSize(size_t size) : void`

---

### **Utils**

-   **Methods:**
    -   `static std::string getFileExtension(const std::string& filePath) : std::string`

---

## **How to Use**

1. **Create an `AudioFileHandler`**: The `AudioFileHandler` class is used to load, manipulate, and save audio files. The appropriate handler (e.g., `WaveAudioFileHandler`) is created using the `AudioFileHandlerFactory`.

2. **Choose a Processing Strategy**: You can choose a strategy from `ChangeAudioVolumeStrategy`, `ReverbStrategy`, `ReverseAudioStrategy`, `SpeedChangeStrategy`, etc., to apply to your audio file.

3. **Apply the Strategy**: After choosing a strategy, you can apply it to the audio by calling the `process()` method on the strategy instance.

4. **Save the Processed Audio**: Once the processing is done, you can save the result to a new audio file.

Example:

```cpp
// Create audio file handler using the factory
std::shared_ptr<AudioFileHandler> fileHandler = AudioFileHandlerFactory::createAudioFileHandler("wav");

// Choose and apply a strategy
std::shared_ptr<AudioProcessingStrategy> strategy = AudioProcessingStrategyFactory::createStrategy("reverse");
auto processedSignal = strategy->process(fileHandler);

// Save the processed signal
fileHandler->saveAudio("output_reversed_audio.wav", processedSignal, fileHandler->getSampleRate());
```

---

## **Dependencies**

The following libraries have been used for the build and execution of the project:

### 1. **kissfft** (for FFT and IFFT processing)
   - **Library**: [kissfft](https://github.com/mborgerding/kissfft)
   - **Description**: A simple, efficient FFT (Fast Fourier Transform) implementation. It is used in this project for both FFT (transforming time-domain signals into the frequency domain) and IFFT (inverse transformation).

### 2. **Google Test** (for unit testing)
   - **Library**: [Google Test](https://github.com/google/googletest)
   - **Description**: Google Test is a C++ testing framework used for writing unit tests to ensure the correctness of the components in the project.

---
