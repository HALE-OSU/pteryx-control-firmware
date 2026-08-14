/**
 * Converts a current (Amps) to a pressure (PSI)
 * pressure = current*linearCalibration + constantCalibration
 */
float currentToPressure(float current, float linearCalibration,
                        float constantCalibration) {
    return current * linearCalibration + constantCalibration;
}