<template>
    <div>
        <div class="preloader"></div>

        <section class="main">
            <div class="container">
                <div class="table">
                    <div class="table_box">
                        <div class="left_column table_item">
                            <div class="row" data-row="row_1">Название:</div>
                            <div class="row" data-row="row_2">Общее время:</div>
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
                            <div class="row" data-row="row_13">Уровень PH <input type="button" class="measure"
                                                                                 data-name="Уровень PH"
                                                                                 value="Измерить"></div>
                            <div class="row" data-row="row_14">Уровень TDS <input type="button" class="measure"
                                                                                  data-name="Уровень TDS"
                                                                                  value="Измерить"></div>
                            <div class="row" data-row="row_15">Фото:</div>
                            <div class="row" data-row="row_16">Комментарий:</div>
                        </div>
                        <div class="table_content table_item" id="table_content">
                            <div class="column" v-for="device in devices">
                                <div class="row" data-row="row_1">
                                    <button class="button top change_name"><img src="/static/img/comment_img.png"
                                                                                alt=""></button>
                                    <a v-bind:href="'/statistics/' +device.id" class="button bottom statistics_open"><img
                                            src="/static/img/statistics_img.png" alt=""></a> {{device.name_owner}}
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
                                <div class="row" data-row="row_12">Lorem ipsum dolor sit amet, consectetuer adipiscing
                                    elit, sed diam nonummy nibh euismod tincidunt ut laoreet
                                </div>
                                <div class="row" data-row="row_13"></div>
                                <div class="row" data-row="row_14"></div>
                                <div class="row" data-row="row_15">
                                    <a href="/static/img/img1.jpg" data-fancybox="gallery" class="image_overlay">
                                        <img src="/static/img/img1.jpg" alt="">
                                    </a>
                                </div>
                                <div class="row" data-row="row_16">
                                    <button class="button top comment_open"><img src="/static/img/comment_img.png"
                                                                                 alt=""></button>
                                    <p class="comment_text">
                                        Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh
                                        euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad
                                        minim veniam, quis nostrud exerci tation ullamco.
                                    </p>
                                </div>
                            </div>
                            <button class="arrow" id="slide_left"><img src="/static/img/arrow_right.png" alt="">
                            </button>
                        </div>
                    </div>
                </div>
            </div>
        </section>
        <div id="overlay"></div>
    </div>
</template>


<script>
    import axios from 'axios'
    export default{
        name: 'device-list',
        data () {
            return {
                devices: [{id: 1, name: 'Устройство 1'}, {id: 2, name: 'Устройство 2'}]

            }
        },
        mounted: function () {
            console.log('mounted')
        },
        created: function () {

            const path = `http://lerts91.fvds.ru/api/device`;
            console.log("created");
            axios.get(path).then(response => {
                console.log(response.data)
                this.devices = response.data
            }).
                catch(error => {
                    console.log(error);
            })



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
