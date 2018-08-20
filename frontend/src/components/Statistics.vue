<template>
    <div>
        <div class="preloader"></div>
        <header>
            <div class="container">
                <div class="title">
                    <h1 class="h1">Статистика: <span>Устройство 1</span></h1>
                    <div class="close_statistic">
                        <!--<img class="normal" src="/static/img/close_statistic.png" alt="">-->
                        <router-link to="/">X</router-link>
                        <!--<img class="hover" src="/static/img/close_statistic_hover.png" alt="">-->
                    </div>
                </div>
            </div>
        </header>
        <section class="statistics">
            <div class="container">
                <div class="statistics_change">

                    <div class="element">
                        <span>Ч-сть обновления данных:</span>
                        <div class="sort_select">
                            <div class="sort_option" data-custom="Device1">
                                <span class="text">Показатель 1</span>
                                <span class="arrow"><img src="/static/img/select_button.png" alt=""></span>
                            </div>
                            <ul class="sort_options">
                                <li data-custom="Device1">Показатель 1</li>
                                <li data-custom="Device2">Показатель 2</li>
                                <li data-custom="Device3">Показатель 3</li>
                                <li data-custom="Device4">Показатель 4</li>
                                <li data-custom="Device4">Показатель 5</li>
                                <li data-custom="Device4">Показатель 6</li>
                            </ul>
                        </div>
                    </div>
                    <div class="element">
                        <span>Ч-сть полива линии 1:</span>
                        <div class="sort_select">
                            <div class="sort_option" data-custom="Device1">
                                <span class="text">Показатель 1</span>
                                <span class="arrow"><img src="/static/img/select_button.png" alt=""></span>
                            </div>
                            <ul class="sort_options">
                                <li data-custom="Device1">Показатель 1</li>
                                <li data-custom="Device2">Показатель 2</li>
                                <li data-custom="Device3">Показатель 3</li>
                                <li data-custom="Device4">Показатель 4</li>
                                <li data-custom="Device4">Показатель 5</li>
                                <li data-custom="Device4">Показатель 6</li>
                            </ul>
                        </div>
                    </div>
                    <div class="element">
                        <span>Ч-сть полива линии 2:</span>
                        <div class="sort_select">
                            <div class="sort_option" data-custom="Device1">
                                <span class="text">Показатель 1</span>
                                <span class="arrow"><img src="/static/img/select_button.png" alt=""></span>
                            </div>
                            <ul class="sort_options">
                                <li data-custom="Device1">Показатель 1</li>
                                <li data-custom="Device2">Показатель 2</li>
                                <li data-custom="Device3">Показатель 3</li>
                                <li data-custom="Device4">Показатель 4</li>
                                <li data-custom="Device4">Показатель 5</li>
                                <li data-custom="Device4">Показатель 6</li>
                            </ul>
                        </div>
                    </div>
                    <div class="element">
                        <span>Ч-сть фотографирования:</span>
                        <div class="sort_select">
                            <div class="sort_option" data-custom="Device1">
                                <span class="text">Показатель 1</span>
                                <span class="arrow"><img src="/static/img/select_button.png" alt=""></span>
                            </div>
                            <ul class="sort_options">
                                <li data-custom="Device1">Показатель 1</li>
                                <li data-custom="Device2">Показатель 2</li>
                                <li data-custom="Device3">Показатель 3</li>
                                <li data-custom="Device4">Показатель 4</li>
                                <li data-custom="Device4">Показатель 5</li>
                                <li data-custom="Device4">Показатель 6</li>
                            </ul>
                        </div>
                    </div>
                    <div class="element">
                        <span>культура 1:</span>
                        <input type="text" name="Показатель">
                    </div>
                    <div class="element">
                        <span>культура 2:</span>
                        <input type="text" name="Показатель">
                    </div>
                    <div class="element">
                        <span>сорт 1:</span>
                        <input type="text" name="Показатель">
                    </div>
                    <div class="element">
                        <span>сорт 2:</span>
                        <input type="text" name="Показатель">
                    </div>
                </div>
            </div>
        </section>
        <section class="main main_statistics">
            <div class="container">
                <div class="table">
                    <div class="table_box">
                        <div class="left_column table_item">
                            <div class="row" data-row="row_1">Время/Дата/День:</div>
                            <div class="row" data-row="row_2">Освещение:</div>
                            <div class="row" data-row="row_3">Культура 1 линия:</div>
                            <div class="row" data-row="row_4">Культура 2 линия:</div>
                            <div class="row" data-row="row_5">Сорт 1 линия:</div>
                            <div class="row" data-row="row_6">Сорт 2 линия:</div>
                            <div class="row" data-row="row_7">Влажность 1 линия:</div>
                            <div class="row" data-row="row_8">Влажность 2 линия:</div>
                            <div class="row" data-row="row_9">Уровень воды:</div>
                            <div class="row" data-row="row_10">Температура воздуха:</div>
                            <div class="row" data-row="row_11">Влажность воздуха:</div>
                            <div class="row" data-row="row_12">Расход электроэнергии:</div>
                            <div class="row" data-row="row_13">Уровень PH </div>
                            <div class="row" data-row="row_14">Уровень TDS </div>
                            <div class="row" data-row="row_15">Фото:</div>
                            <div class="row" data-row="row_16">Комментарий:</div>
                        </div>
                        <div class="table_content table_item" id="table_content">
                            <div class="column">
                                <div class="row" data-row="row_1">
                                    22.07.2018
                                </div>
                                <div class="row" data-row="row_2"></div>
                                <div class="row" data-row="row_3"></div>
                                <div class="row" data-row="row_4"></div>
                                <div class="row" data-row="row_5"></div>
                                <div class="row" data-row="row_6"></div>
                                <div class="row" data-row="row_7"></div>
                                <div class="row" data-row="row_8"></div>
                                <div class="row" data-row="row_9"></div>
                                <div class="row" data-row="row_10"></div>
                                <div class="row" data-row="row_11"></div>
                                <div class="row" data-row="row_12"></div>
                                <div class="row" data-row="row_13"></div>
                                <div class="row" data-row="row_14"></div>
                                <div class="row" data-row="row_15">
                                    <a href="/static/img/img1.jpg" data-fancybox="gallery" class="image_overlay">
                                        <img src="/static/img/img1.jpg" alt="">
                                    </a>
                                </div>
                                <div class="row" data-row="row_16">

                                    <p class="comment_text">
                                        Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamco.
                                    </p>
                                    <p class="comment_text">
                                        Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh.
                                    </p>
                                </div>
                            </div>
                            <button class="arrow" id="slide_left"><img src="/static/img/arrow_right.png" alt=""></button>
                        </div>
                    </div>
                </div>
            </div>
        </section>

        <div class="modal">
            <div class="close_modal"><img src="/static/img/close_modal.png" alt=""></div>
            <div class="title"><span>Уровень PH</span></div>
            <form>
                <div class="modal_content">
                    <div class="element">
                        <span>Показатель:</span>
                        <input type="text" name="Показатель" required>
                    </div>
                    <div class="element">
                        <span>Устройство:</span>
                        <div class="sort_select">
                            <div class="sort_option" data-custom="Device1">
                                <span class="text">Устройство 1</span>
                                <span class="arrow"><img src="/static/img/select_button.png" alt=""></span>
                            </div>
                            <ul class="sort_options">
                                <li data-custom="Device1">Устройство 1</li>
                                <li data-custom="Device2">Устройство 2</li>
                                <li data-custom="Device3">Устройство 3</li>
                                <li data-custom="Device4">Устройство 4</li>
                                <li data-custom="Device4">Устройство 5</li>
                                <li data-custom="Device4">Устройство 6</li>
                            </ul>
                        </div>
                    </div>
                    <div class="element">
                        <input type="submit" class="add_table" value="Добавить">
                    </div>
                </div>
            </form>
        </div>
        <div id="overlay"></div>
    </div>
</template>
<script>
    import axios from 'axios'
    export default{
        name: 'device-list',
        data () {
            return {

            }
        },
        created () {

        },
        mounted: function () {
            console.log('mounted')
        },
        created: function () {
            $(function ($) {
                $(".table_box .left_column").each(function () {
                    var length = $(this).find('.row').length;
                    for (var i = 1; i < length + 1; i++) {
                        var max_col_height = 0;
                        $('[data-row="row_' + i + '"]').each(function () {
                            if ($(this).height() > max_col_height) {
                                max_col_height = $(this).height();
                            }
                        });
                        $('[data-row="row_' + i + '"]').height(max_col_height);
                    }
                });
            });
        },
        methods: {}
    }
</script>
