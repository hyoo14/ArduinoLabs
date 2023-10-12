#ifndef DIGIPIN_H
#define DIGIPIN_H

class Pin {
public:
    explicit Pin(int p);

    void set_TCCRA();
    void set_TCCRB(int wgm, int cs1, int cs0);
    void set_TCNT();
    void set_OCR(int value);
    void set_TIMSK(int value);
    void factor_OCR(int factor);

private:
    int pin;
};

#endif
