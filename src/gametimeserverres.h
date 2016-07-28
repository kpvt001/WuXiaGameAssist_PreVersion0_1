
/*
 * This class is not a public interface, so, it can use Qt class.
 * It's better to use a private class to hold Qt class, instead,
 * this class hold the qt class;
 */
#ifndef GAMETIMESERVERRES_H
#define GAMETIMESERVERRES_H

#include "pretable.h"
#include "projcommon.h"

namespace wuxia {
class GameTimeServerRes
{
public:
    static GameTimeServerRes& Instance();

    const QList<QString>* time_names() const { return &time_names_; }
    const QList<QTime>* first_start_real_times() const { return &first_start_real_times_; }

    int hours_per_game_day() const {return hours_per_game_day_; }
    int game_time_indexs_count() const {return game_time_indexs_count_; }

private:
    GameTimeServerRes();
    virtual ~GameTimeServerRes();

    void LoadConfigs();
    void LoadTimeNames();
    void LoadFirstStartRealTimes();
    void LoadGameTimeIndexsCount();
    void LoadHoursPerGameDay();

    QList<QString> time_names_;
    QList<QTime> first_start_real_times_;

    int game_time_indexs_count_;
    int hours_per_game_day_;

    DISALLOW_COPY_AND_ASSIGN(GameTimeServerRes);
};
} // namespace wuxia

#endif // GAMETIMESERVERRES_H
