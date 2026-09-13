namespace PressureCalculations {
// This is an example function documentation comment! Write one for each
// function :)
/**
 * Brief description of the function. Explain any edge cases (like divide by
 * zero errors)
 *
 * @param input - for each parameter, explain what it is
 * @param ... - repeat for any other parameters
 *
 * @returns explain what value the function returns here
 */
float analogInputToVoltage(int input);

float voltageToCurrent(float voltage, float resistance);

float currentToPressure(float current, float linearCalibration,
                        float constantCalibration);
}  // namespace PressureCalculations